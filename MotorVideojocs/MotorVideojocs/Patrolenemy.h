#pragma once
#include "Enemy.h"

// Enemic que patrulla entre dos punts
class PatrolEnemy : public Enemy {
private:
    float leftLimit;
    float rightLimit;

public:
    PatrolEnemy(float x, float y, float leftLim, float rightLim, float spd);

    void update(float dt) override;
};