#include "../Entities.h"

enum class Direction {
    DOWN = 0,
    LEFT = 1,
    RIGHT = 2,
    UP = 3
};

enum class State {
    IDLE,
    WALK
};

class Player : public Entity {
private:
    float maxMP;
    float currentMP;

    float maxSTA;
    float currentSTA;

public:
    Player();
    ~Player() override;
    
    void Update() override;
    void Draw() override;

    void HandleInput();
};