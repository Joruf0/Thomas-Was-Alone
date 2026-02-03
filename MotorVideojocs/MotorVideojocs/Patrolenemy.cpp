#include "PatrolEnemy.h"

PatrolEnemy::PatrolEnemy(float x, float y, float leftLim, float rightLim, float spd)
    : Enemy(x, y, 40, 40, spd) {
    leftLimit = leftLim;
    rightLimit = rightLim;
    shape.setFillColor(Color(255, 100, 0)); // Taronja
}

void PatrolEnemy::update(float dt) {
    // Moviment horitzontal
    position.x += velocity.x * dt;

    // Comprova límits i canvia direcció
    if (position.x <= leftLimit && !movingRight) {
        position.x = leftLimit;
        changeDirection();
    }
    else if (position.x >= rightLimit && movingRight) {
        position.x = rightLimit;
        changeDirection();
    }

    shape.setPosition(position);
}