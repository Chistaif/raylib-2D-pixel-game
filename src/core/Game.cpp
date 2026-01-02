#include "Game.h"

Game::Game(int screenWidth, int screenHeight) {
    camera = {0};
    camera.target = (Vector2){player.position.x + 20.0f, player.position.y + 20.0f};
    camera.offset = (Vector2){screenWidth/2.0f, screenHeight/2.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
}

void DrawGrid2D(int slices, int spacing) {
    int size = slices * spacing;
    for (int i = 0; i <= size; i += spacing) {
        DrawLine(i, 0, i, size, LIGHTGRAY); // Dọc
        DrawLine(0, i, size, i, LIGHTGRAY); // Ngang
    }
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
    BeginMode2D(camera);
        // Vẽ lưới
        DrawGrid2D(100, 50);
        // Vẽ nhân vật
        player.Draw();
    EndMode2D();
}

void Game::Update() {
    HandleInput();
    // Cập nhật camera theo nhân vật
    camera.target = (Vector2){player.position.x + 20, player.position.y + 20};
}