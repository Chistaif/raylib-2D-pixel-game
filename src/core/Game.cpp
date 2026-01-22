#include "Game.h"
#include "Config.h"

Game::Game(){
    InitWindow(Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT, Config::GAME_TITLE);
    SetTargetFPS(Config::TARGET_FPS);
}

Game::~Game(){
    CloseWindow();
}

void Game::Run(){
    while(!WindowShouldClose()){
        Update();
        Draw();
    }
}

void Game::Update(){

}

void Game::Draw(){
    BeginDrawing();
        ClearBackground(RAYWHITE);
        
    EndDrawing();
}