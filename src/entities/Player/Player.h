#pragma once
#include "raylib.h"

#include "../Entity.h"

class Player : public Entity {
private:
    float ManaPoint;
    float Stamina;

    Texture2D texture; // Chứa ảnh player
    Rectangle frameRec; // Khung cắt ảnh (Cửa sổ nhìn)
    int currFrame; // Kiểm soát frame (Cột thứ 1, 2, 4, ...)
    float frameCounter; // Bộ đếm thời gian

public:
    Player();
    ~Player();

    float currMana;
    float currStamina;

    void Draw();
    void DrawUI(int x, int y);

    void Move(Vector2 direc, float currSpeed) override;

    void UpdateHealth(int point);
    void UpdateStamina(float point);

    void ReduceStamina(float point);
};