#include "raylib.h"
#include "entities/Player.h"

class Game {
private:
    Camera2D camera;

    void MoveLeft();
    void MoveRight();
    void MoveUp();
    void MoveDown();
    // void MoveUpLeft();
    // void MoveUpRight();
    // void MoveDownLeft();
    // void MoveDownRight();
    // void Sprint();

    public:
    Game(int screenWidth, int screenHeight);
    ~Game() = default;
    Player player;
    
    void HandleInput();
    void Update();
    void Draw();
};