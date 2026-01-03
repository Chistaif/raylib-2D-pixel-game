#include "Dummy.h"

Dummy::Dummy(float x, float y, Player* target) : Enemy(target) {
    position = {x, y};
    HealthPoint = 1000.0f;
    currHealth = 1000.0f;
    Speed = 0.0f;
}

void Dummy::Draw() {
    DrawHealthBar(10.0f);
    DrawRectangleV(position, {32, 32}, DARKBROWN);
    DrawRectangleLines(position.x, position.y, 32, 32, BLACK);
}

void Dummy::AIUpdate(float dt) {
    // Để trống để không di chuyển
}