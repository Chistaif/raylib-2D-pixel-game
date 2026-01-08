#include "Game.h"

Game::Game(int screenWidth, int screenHeight) {
    player = new Player();
    enemies.push_back(new Dummy(0, 0, player));

    camera = {0};
    camera.target = (Vector2){player->position.x + 16.0f, player->position.y + 16.0f};
    camera.offset = (Vector2){screenWidth/2.0f, screenHeight/2.0f};
    camera.rotation = 0.0f;
    camera.zoom = 2.5f;

    lastDirec = {0.0f, 1.0f}; // Mặc định là nhìn xuống
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

void Game::UpdateCameraCenter(){
    // Mục tiêu: Camera luôn nhìn vào giữa tâm nhân vật (cộng thêm offset để căn giữa sprite 32x32)
    Vector2 targetPos = {player->position.x + 16.0f, player->position.y + 16.0f};

    camera.target.x += (targetPos.x - camera.target.x) * 0.1f;
    camera.target.y += (targetPos.y - camera.target.y) * 0.1f;

    float wheel = GetMouseWheelMove();

    if (wheel != 0) {
        const float zoomIncrement = 0.125f;

        camera.zoom += (zoomIncrement * wheel);

        if (camera.zoom < 0.5f) camera.zoom = 0.5f;
        if (camera.zoom > 5.0f) camera.zoom = 5.0f;
        
        TraceLog(LOG_INFO, "Current Zoom: %f", camera.zoom);
    }
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

    UpdateCameraCenter();
}