#pragma once
#include "raylib.h"

class Player{
private:
    int AttackPoint;
    int HealthPoint;
    int DefendPoint;
    float Speed;
    
public:
    Player();
    ~Player() = default;
    Vector2 position;
    
    void Draw();
    void Move(float directionX, float directionY);
};