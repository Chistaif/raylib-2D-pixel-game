#include "Enemy.h"
#include "../Player/Player.h"
#include "raymath.h"

Enemy::Enemy(Player* target) : Entity(10.0f, 10.0f, 250.0f, 150.0f) {
    this->target = target;
    detecRange = 200.0f;
}

Enemy::~Enemy(){
    target = nullptr;
}

void Enemy::DrawHealthBar(float yOffSet){
    if(currHealth < HealthPoint && currHealth > 0){ // Điều kiện chỉ vẽ khi bị tấn công hoặc còn sống
        int barWidth = 32.0f;
        int barHeight = 5.0f;
        
        // Tính toán vị trí đặt thanh bar
        float barX = position.x;
        float barY = position.y - yOffSet;
        float percenHP = currHealth / HealthPoint;

        DrawRectangle(barX, barY, barWidth, barHeight, Fade(DARKGRAY, 0.5f)); // Nền xám
        DrawRectangle(barX, barY, barWidth * percenHP, barHeight, RED); // Máu đỏ
        DrawRectangleLines(barX, barY, barWidth, barHeight, BLACK); // Viền đen
    }
}

void Enemy::AIUpdate(float dt){
    if(target != nullptr){
        float dist = Vector2Distance(position, target->position);
        if(dist < detecRange){
            Vector2 direc = Vector2Normalize(Vector2Subtract(target->position, position));
            Move(direc, 0);
        }
    }
}