#pragma once
#include "raylib.h"
#include "Config.h"

class Game {
private:
    void Update();
    void Draw();
public:
    Game();
    ~Game();

    void Run();
};