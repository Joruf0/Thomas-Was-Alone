#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class GameObject {
protected:
    Vector2f position;
    RectangleShape shape;

public:
    GameObject(float x, float y, float width, float height);

    virtual void update(float dt) = 0;  // Mètode virtual pur

    virtual void draw(RenderWindow& window);

    FloatRect getBounds();

    Vector2f getPosition();

    void setPosition(float x, float y);
};
