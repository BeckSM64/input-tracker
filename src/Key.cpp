#include <iostream>
#include <windows.h>

#include "Key.h"

Key::Key() {
    // Default constructor
}

Key::Key(const sf::Vector2f KEY_SIZE,
         const sf::Vector2f KEY_POSITION,
         const sf::Color KEY_COLOR,
         const std::string TEXT_STRING,
         const int TEXT_SIZE,
         sf::Color textColor,
         int keyForAsyncCheck) {

    Key::KEY_SIZE = KEY_SIZE;
    Key::KEY_POSITION = KEY_POSITION;
    Key::KEY_COLOR = KEY_COLOR;
    Key::TEXT_STRING = TEXT_STRING;
    Key::TEXT_SIZE = TEXT_SIZE;
    Key::textColor = textColor;
    Key::keyForAsyncCheck = keyForAsyncCheck;

    // Initialize SFML stuff
    Key::Init();

}

void Key::Init() {

    // Load font with path relative to output directory of generated executable
    if(!Key::font.loadFromFile("./fonts/arial.ttf")){
        std::cout << "Error loading font" << std::endl;
    }

    // Setup text
    Key::keyText.setString(Key::TEXT_STRING);
    Key::keyText.setCharacterSize(50);
    Key::keyText.setFillColor(sf::Color::White);

    // Setup key
    Key::keyShape = sf::RectangleShape(KEY_SIZE);
    Key::keyShape.setFillColor(KEY_COLOR);
    Key::keyShape.setPosition(KEY_POSITION);
}

void Key::Update() {

    // Change key color depending on input
    if(GetAsyncKeyState(Key::keyForAsyncCheck)) {
        Key::keyShape.setFillColor(sf::Color::White);
        Key::keyText.setFillColor(sf::Color::Blue);
    } else {
        Key::keyShape.setFillColor(sf::Color::Blue);
        Key::keyText.setFillColor(sf::Color::White);
    }
}

void Key::Draw(sf::RenderWindow &win) {

    // TODO: Probably shouldn't do all this every frame but nothing else seems to be working
    // Not sure why this isn't working when set in Init(), appears to be going out of scope
    // somehow despite fong being a member variable of the class
    Key::keyText.setFont(Key::font);

    // Center text on key
    sf::FloatRect textRect = keyText.getLocalBounds();
    keyText.setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);
    sf::Vector2f newKeyPosition = sf::Vector2f(KEY_POSITION.x + (KEY_SIZE.x/2.0f), KEY_POSITION.y + (KEY_SIZE.y/2.0f));
    Key::keyText.setPosition(newKeyPosition);

    // Draw to window
    win.draw(Key::keyShape);
    win.draw(Key::keyText);
}
