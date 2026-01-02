#include "Player.h"

Player::Player() {
    HealthPoint = 100;
    AttackPoint = 10;
    DefendPoint = 10;
    Speed = 200.0f; // Pixel per second

    position = { 100.0f, 100.0f };
}

void Player::Draw() {
    DrawRectangleV(position, { 40, 40 }, RED);
}

void Player::Move(float directionX, float directionY) {
    float dt = GetFrameTime(); // Lấy độ trễ khung hình, làm mượt chuyển động
    position.x += directionX * Speed * dt;
    position.y += directionY * Speed * dt;
}