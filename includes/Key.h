#pragma once

#include <SFML/Graphics.hpp>

class Key {

    public:

        Key();
        Key(const sf::Vector2f KEY_SIZE,
            const sf::Vector2f KEY_POSITION,
            const sf::Color KEY_COLOR,
            const std::string TEXT_STRING,
            const int TEXT_SIZE,
            sf::Color textColor);
        void Draw(sf::RenderWindow &win);

    protected:

        // Key font
        sf::Font font;

        // Key text
        sf::Text keyText;

        // Key shape
        sf::RectangleShape keyShape;

        sf::Vector2f KEY_SIZE;
        sf::Vector2f KEY_POSITION;
        sf::Color KEY_COLOR;
        std::string TEXT_STRING;
        int TEXT_SIZE;
        sf::Color textColor;
};
