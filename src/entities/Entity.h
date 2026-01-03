#pragma once
#include "raylib.h"

class Entity {
private:
protected:
    float AttackPoint;
    float DefendPoint;
    float HealthPoint;
    float Speed;

    float currHealth;

public:
    Entity(float AttackPoint, float DefendPoint, float HealthPoint, float Speed);
    virtual ~Entity() = default;
    
    Vector2 position;

    virtual void Draw() = 0; // Vẽ thực thể

    virtual void TakeDame(float point); // Thực thể nhận dame
    virtual void Move(Vector2 direc, float currSpeed); // Di chuyển cho thực thể 
};