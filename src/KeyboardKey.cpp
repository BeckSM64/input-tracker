#include <iostream>

#include "KeyboardKey.h"
#include "Key.h"

KeyboardKey::KeyboardKey() {
    // Default constructor
}

KeyboardKey::KeyboardKey(const sf::Vector2f KEY_SIZE,
         const sf::Vector2f KEY_POSITION,
         const sf::Color KEY_COLOR,
         const std::string TEXT_STRING,
         const int TEXT_SIZE,
         sf::Color textColor,
         sf::Keyboard::Key keyCode) : Key(KEY_SIZE, KEY_POSITION, KEY_COLOR, TEXT_STRING, TEXT_SIZE, textColor) {

    this->keyCode = keyCode;
}

void KeyboardKey::Update() {

    if (sf::Keyboard::isKeyPressed(keyCode)) {

        // Set key visually to inactive
        this->keyShape.setFillColor(sf::Color::White);
        this->keyText.setFillColor(sf::Color::Blue);
    } else {

        // Set key visually to active
        this->keyShape.setFillColor(sf::Color::Blue);
        this->keyText.setFillColor(sf::Color::White);
    }
}
