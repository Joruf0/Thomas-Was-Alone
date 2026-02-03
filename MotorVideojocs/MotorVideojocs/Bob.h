#pragma once
#include "Character.h"

class Bob : public Character {
public:
    Bob(float x, float y);

    void handleInput() override;
};