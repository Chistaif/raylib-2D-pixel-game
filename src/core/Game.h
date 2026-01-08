#include <vector>
#include "raylib.h"
#include "raymath.h"
#include "entities/Entity.h"
#include "entities/Player/Player.h"
#include "entities/Enemy/Enemy.h"
#include "entities/Enemy/Dummy/Dummy.h"

#include <string>

class Game {
private:
    Camera2D camera;
    Vector2 lastDirec; // Nhớ hướng di chuyển cuối cùng

    Player* player;
    std::vector<Enemy*> enemies;

    void Attack();
    void UpdateCameraCenter();
public:
    Game(int screenWidth, int screenHeight);
    ~Game(); 
    
    void HandleInput();
    void Update();
    void Draw();
};