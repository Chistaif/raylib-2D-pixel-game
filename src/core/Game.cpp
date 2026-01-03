#include "Game.h"

Game::Game(int screenWidth, int screenHeight) {
    player = new Player();
    enemies.push_back(new Dummy(0, 0, player));

    camera = {0};
    camera.target = (Vector2){player->position.x + 20.0f, player->position.y + 20.0f};
    camera.offset = (Vector2){screenWidth/2.0f, screenHeight/2.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    lastDirec = {1.0f, 0.0f}; // Mặc định là nhìn sang phải
}

Game::~Game(){
    delete player;

    for(auto x : enemies){
        delete x;
    }
    enemies.clear();
}

void DrawGrid2D(int slices, int spacing) {
    int size = slices * spacing;
    for (int i = -size; i <= size; i += spacing) {
        DrawLine(i, -size, i, size, LIGHTGRAY); // Dọc
        DrawLine(-size, i, size, i, LIGHTGRAY); // Ngang
    }

    DrawLine(0, size, 0, -size, BLACK);
    DrawLine(-size, 0, size, 0, BLACK);
}

void Game::HandleInput() {
    Vector2 direc = {0.0f, 0.0f};
    if(IsKeyDown(KEY_A)) direc.x -= 1.0f;
    if(IsKeyDown(KEY_D)) direc.x += 1.0f;
    if(IsKeyDown(KEY_W)) direc.y -= 1.0f;
    if(IsKeyDown(KEY_S)) direc.y += 1.0f;
    
    if(direc.x != 0 || direc.y != 0) { // Nếu đứng yên hoặc phím ngược hướng nhau thì điều kiện false, tránh trường hợp Vector2Normalize lỗi 0/0
        direc = Vector2Normalize(direc); // Vector2Normalize lấy độ vector cũ chia cho độ dài chính nó
        lastDirec = direc; // Lưu lại hướng cuối cùng dùng cho Sprint khi đứng yên
    }
    float currSpeed = 0;
    if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
        player->position.x += lastDirec.x * 100;
        player->position.y += lastDirec.y * 100;
    }
    if(IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
        currSpeed += 200;
    }
    if(direc.x != 0 || direc.y != 0) {
        player->Move(direc, currSpeed);
    }

    if(IsKeyPressed(KEY_SPACE)){
        if (!enemies.empty()) {
            enemies[0]->TakeDame(10);
        }
    }
}
 
void Game::Draw() {
    BeginMode2D(camera);
        // Vẽ lưới
        DrawGrid2D(100, 32);
        // Vẽ nhân vật
        player->Draw();
        for(auto x : enemies){
            x->Draw();
        }
    EndMode2D();

    player->DrawUI(20, 20);
}

void Game::Update() {
    // Nhận input từ người dùng
    HandleInput();

    // Cho quái suy nghĩ và di chuyển
    float dt = GetFrameTime();
    for (Enemy* e : enemies) {
        e->AIUpdate(dt);
    }
    // Cập nhật camera theo nhân vật
    camera.target = (Vector2){player->position.x + 20, player->position.y + 20};
}