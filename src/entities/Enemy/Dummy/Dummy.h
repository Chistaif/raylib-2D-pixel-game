#pragma once
#include "../Enemy.h"

class Dummy : public Enemy {
private:
public:
    Dummy(float x, float y, Player* target);
    ~Dummy() = default;

    void Draw() override;
    void AIUpdate(float dt) override;
};