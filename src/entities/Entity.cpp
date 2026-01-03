#include "Entity.h"

Entity::Entity(float AttackPoint, float DefendPoint, float HealthPoint, float Speed){
    this->AttackPoint = AttackPoint;
    this->DefendPoint = DefendPoint;
    this->HealthPoint = HealthPoint;
    this->Speed = Speed;

    currHealth = HealthPoint;
    position = {0, 0};
}

void Entity::Move(Vector2 direc, float currSpeed){
    float dt = GetFrameTime(); // Lấy độ trễ khung hình, làm mượt chuyển động
    position.x += direc.x * (Speed + currSpeed) * dt;
    position.y += direc.y * (Speed + currSpeed) * dt;
}

void Entity::TakeDame(float point){
    currHealth -= point;
    if(currHealth < 0) {
        currHealth = 0;
    }
}