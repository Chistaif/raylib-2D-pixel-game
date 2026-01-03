#include "Player.h"

Player::Player() : Entity(10.0f, 10.0f, 250.0f, 200.0f) {
    ManaPoint = 100.0f;
    Stamina = 100.0f;

    currMana = ManaPoint;
    currStamina = Stamina;

    position = { 64.0f, 64.0f };
}

void Player::Draw() {
    DrawRectangleV(position, { 32, 32 }, RED);
}

void Player::DrawUI(int x, int y) {
    // Cấu hình giao diện
    float maxWidth = 200.0f;
    float maxHeight = 20.0f;
    float barGap = 5.0f;

    // 1. Thanh HP
    float percenHP = currHealth / HealthPoint;
    DrawRectangle(x, y, maxWidth, maxHeight, Fade(DARKGRAY, 0.5f)); // Nền xám
    DrawRectangle(x, y, maxWidth * percenHP, maxHeight, RED); // Máu đỏ
    DrawRectangleLines(x, y, maxWidth, maxHeight, BLACK); // Viền đen
    const char* hpText = TextFormat("%d/%d", (int)currHealth, (int)HealthPoint);
    int textWidthHP = MeasureText(hpText, 20);
    // Công thức căn giữa: Tọa độ X + (thanh - chữ) / 2
    DrawText(hpText, x + (maxWidth - textWidthHP) / 2, y + 1, 20, WHITE);

    // 2. Thanh Mana
    float percenMP = currMana / ManaPoint;
    float yMana = y + barGap + maxHeight;
    DrawRectangle(x, yMana, maxWidth, maxHeight, Fade(DARKGRAY, 0.5f)); // Nền xám
    DrawRectangle(x, yMana, maxWidth * percenMP, maxHeight, DARKBLUE); // Mana xanh
    DrawRectangleLines(x, yMana, maxWidth, maxHeight, BLACK);
    const char* mpText = TextFormat("%d/%d", (int)currMana, (int)ManaPoint);
    int textWidthMP = MeasureText(mpText, 20);
    DrawText(mpText, x + (maxWidth - textWidthMP) / 2, yMana + 1, 20, WHITE);

    // 3. Thanh Stamina
    float percenSP = currStamina / Stamina;
    float ySP = yMana + barGap + maxHeight;
    DrawRectangle(x, ySP, maxWidth, maxHeight, Fade(DARKGRAY, 0.5f)); // Nền xám
    DrawRectangle(x, ySP, maxWidth * percenSP, maxHeight, DARKGREEN); // Stamina xanh
    DrawRectangleLines(x, ySP, maxWidth, maxHeight, BLACK);
    const char* spText = TextFormat("%d/%d", (int)currStamina, (int)Stamina);
    int textWidthSP = MeasureText(spText, 20);
    DrawText(spText, x + (maxWidth - textWidthSP) / 2, ySP + 1, 20, WHITE);
}

void Player::Move(Vector2 direc, float currSpeed) {
    Entity::Move(direc, currSpeed);
}

void Player::UpdateHealth(int point) {
    HealthPoint += point;
}

void Player::UpdateStamina(float point) {
    Stamina += point;
    if(Stamina > 200.0f) {
        Stamina = 200.0f;
    }
}

void Player::ReduceStamina(float point) {
    currStamina -= point;
    if(currStamina < 0){
        currStamina = 0;
    }
}