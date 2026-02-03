#pragma once
#include "GameObject.h"

// Classe DERIVADA per a personatges jugables
class Character : public GameObject {
protected:
    Vector2f velocity;
    bool isJumping;
    const float GRAVITY = 800.0f;
    float speed;
    float jumpForce;

private:
    void update(float dt) override;

public:
    Character(float x, float y, float spd, float jmp);

    virtual void handleInput() = 0;  // Cada personatge té els seus controls

    void update(float dt, int MaxX, int MaxY);

    void setPosition(float x, float y);

    void stopFalling(float groundY);
};