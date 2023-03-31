#include <iostream>

#include "MouseKey.h"
#include "Key.h"

MouseKey::MouseKey() {
    // Default constructor
}

MouseKey::MouseKey(const sf::Vector2f KEY_SIZE,
         const sf::Vector2f KEY_POSITION,
         const sf::Color KEY_COLOR,
         const std::string TEXT_STRING,
         const int TEXT_SIZE,
         sf::Color textColor,
         sf::Mouse::Button mouseCode) : Key(KEY_SIZE, KEY_POSITION, KEY_COLOR, TEXT_STRING, TEXT_SIZE, textColor) {

    this->mouseCode = mouseCode;
}

void MouseKey::Update() {

    if (sf::Mouse::isButtonPressed(mouseCode)) {

        // Set key visually to inactive
        this->keyShape.setFillColor(sf::Color::White);
        this->keyText.setFillColor(sf::Color::Blue);
    } else {

        // Set key visually to active
        this->keyShape.setFillColor(sf::Color::Blue);
        this->keyText.setFillColor(sf::Color::White);
    }
}
