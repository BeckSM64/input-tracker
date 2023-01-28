#include <iostream>

#include "Key.h"

Key::Key() {
    // Default constructor
}

Key::Key(const sf::Vector2f KEY_SIZE,
         const sf::Vector2f KEY_POSITION,
         const sf::Color KEY_COLOR,
         const std::string TEXT_STRING,
         const int TEXT_SIZE,
         const sf::Vector2f TEXT_POSITION,
         sf::Color textColor) {
    
    // Load font with path relative to output directory of generated executable
    if(!Key::font.loadFromFile("./fonts/arial.ttf")){
        std::cout << "Error loading font" << std::endl;
    }

    // Set key text font
    Key::keyText.setFont(Key::font);

    // Setup text
    Key::keyText.setString(TEXT_STRING);
    Key::keyText.setCharacterSize(TEXT_SIZE);
    Key::keyText.setFillColor(textColor);
    Key::keyText.setPosition(0, 0); // TODO: Fix this

    // Setup key
    Key::keyShape = sf::RectangleShape(KEY_SIZE);
    Key::keyShape.setFillColor(KEY_COLOR);
    Key::keyShape.setPosition(KEY_POSITION);

}

void Key::Update() {

}

void Key::Draw(sf::RenderWindow &win) {

    std::cout << "KEY DRAW METHOD" << std::endl;

    win.draw(Key::keyShape);
    win.draw(Key::keyText);
}
