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

    this->KEY_SIZE = KEY_SIZE;
    this->KEY_POSITION = KEY_POSITION;
    this->KEY_COLOR = KEY_COLOR;
    this->TEXT_STRING = TEXT_STRING;
    this->TEXT_SIZE = TEXT_SIZE;
    this->textColor = textColor;
    this->keyForAsyncCheck = keyForAsyncCheck;

    // Initialize SFML stuff
    this->Init();

}

void Key::Init() {

    // Load font with path relative to output directory of generated executable
    if(!this->font.loadFromFile("./fonts/arial.ttf")){
        std::cout << "Error loading font" << std::endl;
    }

    // Setup text
    this->keyText.setString(this->TEXT_STRING);
    this->keyText.setCharacterSize(50);
    this->keyText.setFillColor(sf::Color::White);

    // Setup key
    this->keyShape = sf::RectangleShape(KEY_SIZE);
    this->keyShape.setFillColor(KEY_COLOR);
    this->keyShape.setPosition(KEY_POSITION);
}

void Key::Update() {

    // Change key color depending on input
    if(GetAsyncKeyState(this->keyForAsyncCheck)) {
        this->keyShape.setFillColor(sf::Color::White);
        this->keyText.setFillColor(sf::Color::Blue);
    } else {
        this->keyShape.setFillColor(sf::Color::Blue);
        this->keyText.setFillColor(sf::Color::White);
    }
}

void Key::Draw(sf::RenderWindow &win) {

    // TODO: Probably shouldn't do all this every frame but nothing else seems to be working
    // Not sure why this isn't working when set in Init(), appears to be going out of scope
    // somehow despite fong being a member variable of the class
    this->keyText.setFont(this->font);

    // Center text on key
    sf::FloatRect textRect = keyText.getLocalBounds();
    keyText.setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);
    sf::Vector2f newKeyPosition = sf::Vector2f(KEY_POSITION.x + (KEY_SIZE.x/2.0f), KEY_POSITION.y + (KEY_SIZE.y/2.0f));
    this->keyText.setPosition(newKeyPosition);

    // Draw to window
    win.draw(this->keyShape);
    win.draw(this->keyText);
}
