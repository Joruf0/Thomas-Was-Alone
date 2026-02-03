#include "Enemy.h"

Enemy::Enemy(float x, float y, float width, float height, float spd)
    : GameObject(x, y, width, height) {
    speed = spd;
    velocity = Vector2f(speed, 0);
    movingRight = true;
    shape.setFillColor(Color::Red);
}

void Enemy::update(float dt) {
    // Moviment horitzontal
    position.x += velocity.x * dt;
    shape.setPosition(position);
}

void Enemy::draw(RenderWindow& window) {
    window.draw(shape);
}

void Enemy::changeDirection() {
    movingRight = !movingRight;
    velocity.x = movingRight ? speed : -speed;
}

bool Enemy::checkCollisionWithCharacter(FloatRect characterBounds) {
    return shape.getGlobalBounds().findIntersection(characterBounds).has_value();
}