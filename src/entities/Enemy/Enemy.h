#pragma once

#include "../Entity.h"

class Player; // Khai báo trước tránh tình trạng Player gọi Enemy, Enemy lại gọi Player

class Enemy : public Entity {
protected:
    Player* target;
    float detecRange; // Phạm vi phát hiện

    void DrawHealthBar(float yOffSet); // Vẽ thanh máu
public:
    Enemy(Player* target);
    virtual ~Enemy();

    virtual void Draw() = 0;
    virtual void AIUpdate(float dt); // Cập nhật di chuyển cho quái
};