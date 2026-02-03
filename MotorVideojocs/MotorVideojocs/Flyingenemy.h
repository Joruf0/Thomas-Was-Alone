#pragma once
#include "Enemy.h"

// Enemic volador que es mou verticalment
class FlyingEnemy : public Enemy {
private:
    float topLimit;
    float bottomLimit;
    bool movingUp;

public:
    FlyingEnemy(float x, float y, float topLim, float bottomLim, float spd);

    void update(float dt) override;

    void changeDirectionVertical();
};