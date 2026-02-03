#include "Bob.h"

Bob::Bob(float x, float y) : Character(x, y, 200.0f, -500.0f) {
    // Bob és més lent que Thomas però salta més alt
    // Velocitat: 200 (Thomas té 250)
    // Salt: -500 (Thomas té -450)
    shape.setFillColor(Color::Blue);
}

void Bob::handleInput() {
    // Controls: Fletxes del teclat
    velocity.x = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
        velocity.x = -speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
        velocity.x = speed;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && !isJumping) {
        velocity.y = jumpForce;
        isJumping = true;
    }
}