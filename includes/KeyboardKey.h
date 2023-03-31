#pragma once

#include <SFML/Graphics.hpp>

#include "Key.h"

class KeyboardKey : public Key {

    public:

        KeyboardKey();
        KeyboardKey(const sf::Vector2f KEY_SIZE,
            const sf::Vector2f KEY_POSITION,
            const sf::Color KEY_COLOR,
            const std::string TEXT_STRING,
            const int TEXT_SIZE,
            sf::Color textColor,
            sf::Keyboard::Key keyCode);
        void Update();

    private:
        
        // Key code
        sf::Keyboard::Key keyCode;

};
