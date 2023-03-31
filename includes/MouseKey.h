#pragma once

#include <SFML/Graphics.hpp>

#include "Key.h"

class MouseKey : public Key {

    public:

        MouseKey();
        MouseKey(const sf::Vector2f KEY_SIZE,
            const sf::Vector2f KEY_POSITION,
            const sf::Color KEY_COLOR,
            const std::string TEXT_STRING,
            const int TEXT_SIZE,
            sf::Color textColor,
            sf::Mouse::Button mouseCode);
        void Update();

    private:
        
        // Key code
        sf::Mouse::Button mouseCode;
};
