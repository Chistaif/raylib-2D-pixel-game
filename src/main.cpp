#include "raylib.h"
#include "core/Game.h"

int main(){
    const int screenWidth = 800;
    const int screenHeight = 450;
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