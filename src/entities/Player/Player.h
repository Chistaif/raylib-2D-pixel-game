#pragma once
#include "raylib.h"

#include "../Entity.h"

class Player : public Entity {
private:
    float ManaPoint;
    float Stamina;
public:
    Player();
    ~Player() = default;

    float currMana;
    float currStamina;

    void Draw();
    void DrawUI(int x, int y);

    void Move(Vector2 direc, float currSpeed) override;

    void UpdateHealth(int point);
    void UpdateStamina(float point);

    void ReduceStamina(float point);
};