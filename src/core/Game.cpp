#include "Game.h"

Game::Game(int screenWidth, int screenHeight) {
    camera = {0};
    camera.target = (Vector2){player.position.x + 20.0f, player.position.y + 20.0f};
    camera.offset = (Vector2){screenWidth/2.0f, screenHeight/2.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
}

void Game::HandleInput() {
    if (IsKeyDown(KEY_A)) MoveLeft();
    if (IsKeyDown(KEY_D)) MoveRight();
    if (IsKeyDown(KEY_W)) MoveUp();
    if (IsKeyDown(KEY_S)) MoveDown();
}

void Game::MoveLeft() {
    player.Move(-1.0, 0.0);
}

void Game::MoveRight() {
    player.Move(1.0, 0.0);
}

void Game::MoveUp() {
    player.Move(0.0, -1.0);
}

void Game::MoveDown() {
    player.Move(0.0, 1.0);
}

void Game::Draw() {
    int mapSize = 2000;
    int spacing = 50;
    BeginMode2D(camera);
        // Vẽ lưới
        for(int x = 0 ; x <= mapSize ; x += spacing){
            DrawLine(x, 0, x, mapSize, LIGHTGRAY); // Trục x
        }

        for(int y = 0 ; y <= mapSize ; y += spacing){
            DrawLine(0, y, y, mapSize, LIGHTGRAY); // Trục y
        }
        
        // Vẽ nhân vật
        player.Draw();
    EndMode2D();
}

void Game::Update() {
    HandleInput();
    // Cập nhật camera theo nhân vật
    camera.target = (Vector2){player.position.x + 20, player.position.y + 20};
}
