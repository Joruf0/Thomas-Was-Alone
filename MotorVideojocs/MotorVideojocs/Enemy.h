#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>

using namespace sf;

// Classe base per a enemics (hereta de GameObject)
class Enemy : public GameObject {
protected:
    Vector2f velocity;
    float speed;
    bool movingRight;

public:
    Enemy(float x, float y, float width, float height, float spd);

    virtual void update(float dt) override;

    void draw(RenderWindow& window) override;

    virtual void changeDirection();

    bool checkCollisionWithCharacter(FloatRect characterBounds);
};