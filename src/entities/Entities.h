#include "raylib.h"

class Entity {
private:
    float maxHP;
    float maxAT;
    float maxSP;

    
public:
    Entity();
    ~Entity();

    void Update();
    void Draw();

    void Move();
};