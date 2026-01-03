#include "raylib.h"
#include "core/Game.h"

int main(){
    const int screenWidth = 1600;
    const int screenHeight = 900;
    InitWindow(screenWidth, screenHeight, "MyRPG_Game");
    SetTargetFPS(60);
    Game game(screenWidth, screenHeight);
    while(!WindowShouldClose()){
        game.Update();
        
        BeginDrawing();
            ClearBackground(RAYWHITE);
            game.Draw();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}