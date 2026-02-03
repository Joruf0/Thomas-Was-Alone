#include "FlyingEnemy.h"

FlyingEnemy::FlyingEnemy(float x, float y, float topLim, float bottomLim, float spd)
    : Enemy(x, y, 35, 35, spd) {
    topLimit = topLim;
    bottomLimit = bottomLim;
    movingUp = false;
    velocity = Vector2f(0, speed);
    shape.setFillColor(Color(150, 0, 150)); // Morat
}

void FlyingEnemy::update(float dt) {
    // Moviment vertical
    position.y += velocity.y * dt;

    // Comprova límits i canvia direcció
    if (position.y <= topLimit && movingUp) {
        position.y = topLimit;
        changeDirectionVertical();
    }
    else if (position.y >= bottomLimit && !movingUp) {
        position.y = bottomLimit;
        changeDirectionVertical();
    }

    shape.setPosition(position);
}

void FlyingEnemy::changeDirectionVertical() {
    movingUp = !movingUp;
    velocity.y = movingUp ? -speed : speed;
}