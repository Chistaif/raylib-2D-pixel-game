#include "Entities.h"

Entity::Entity(float HP, float ATK, float DEF,float SP){
    maxHP = HP;
    maxATK = ATK;
    maxDEF = DEF;
    maxSPD = SP;

    currentHP = maxHP;

    position = {0.0f, 0.0f};
}

Entity::~Entity(){}

void Entity::Move(Vector2 direction, float dt){
    position.x += direction.x * dt * maxSPD;
    position.y += direction.y * dt * maxSPD;
}