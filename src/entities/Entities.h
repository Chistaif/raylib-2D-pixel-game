#include "raylib.h"

class Entity {
protected:
    float maxHP;
    float maxATK;
    float maxDEF;
    float maxSPD;

    float currentHP;

    Vector2 position;
public:
    Entity(float maxHP, float maxATK, float maxDEF,float maxSP);
    virtual ~Entity();

    virtual void Update() = 0;
    virtual void Draw();

    void Move(Vector2 direction, float dt);
};