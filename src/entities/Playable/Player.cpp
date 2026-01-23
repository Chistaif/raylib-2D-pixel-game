#include "Player.h"

Player::Player() : Entity(200, 10, 30, 200){
    maxMP = 100;
    maxSTA = 90;

    currentMP = maxMP;
    currentSTA = maxSTA;
}
