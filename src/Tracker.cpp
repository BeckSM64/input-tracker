#include <iostream>
#include <windows.h>
#include <SFML/Graphics.hpp>

#include "Tracker.h"

Tracker::Tracker() {

    Tracker::Setup();
    Tracker::Run();
}

void Tracker::Setup() {

    // Window size constants
    const int WINDOW_WIDTH = 720;
    const int WINDOW_HEIGHT = 520;

    // Key text size constant
    const int KEY_TEXT_SIZE = 50;

    // Key size constants
    const sf::Vector2f LETTER_KEY_SIZE = sf::Vector2f(100, 100);
    const sf::Vector2f SPACE_KEY_SIZE = sf::Vector2f(320, 100);
    const sf::Vector2f SHIFT_KEY_SIZE = sf::Vector2f(210, 100);
    const sf::Vector2f MOUSE_BOX_SIZE = sf::Vector2f(210, 210);
    const sf::Vector2f MOUSE_KEY_SIZE = sf::Vector2f(90, 90);

    // Key position constants
    const sf::Vector2f W_KEY_POSITION = sf::Vector2f(200, 100);
    const sf::Vector2f A_KEY_POSITION = sf::Vector2f(90, 210);
    const sf::Vector2f S_KEY_POSITION = sf::Vector2f(200, 210);
    const sf::Vector2f D_KEY_POSITION = sf::Vector2f(310, 210);
    const sf::Vector2f SHIFT_KEY_POSITION = sf::Vector2f(90, 320);
    const sf::Vector2f SPACE_KEY_POSITION = sf::Vector2f(310, 320);
    const sf::Vector2f MOUSE_BOX_POSITION = sf::Vector2f(420, 100);
    const sf::Vector2f LEFT_MOUSE_KEY_POSITION = sf::Vector2f(430, 110);
    const sf::Vector2f RIGHT_MOUSE_KEY_POSITION = sf::Vector2f(530, 110);

    // Create the window
    Tracker::win.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Input Tracker");

    // Load font with path relative to output directory of generated executable
    if(!Tracker::font.loadFromFile("./fonts/arial.ttf")){
        std::cout << "Error loading font" << std::endl;
    }

    //Set fonts
    Tracker::wText.setFont(font);
    Tracker::sText.setFont(font);
    Tracker::dText.setFont(font);
    Tracker::aText.setFont(font);
    Tracker::spaceText.setFont(font);
    Tracker::shiftText.setFont(font);

    //Create texts
    Tracker::wText.setString("W");
    Tracker::wText.setCharacterSize(KEY_TEXT_SIZE);
    Tracker::wText.setFillColor(sf::Color::White);
    Tracker::wText.setPosition(227, 119);

    Tracker::sText.setString("S");
    Tracker::sText.setCharacterSize(KEY_TEXT_SIZE);
    Tracker::sText.setFillColor(sf::Color::White);
    Tracker::sText.setPosition(233, 229);

    Tracker::dText.setString("D");
    Tracker::dText.setCharacterSize(KEY_TEXT_SIZE);
    Tracker::dText.setFillColor(sf::Color::White);
    Tracker::dText.setPosition(343, 229);

    Tracker::aText.setString("A");
    Tracker::aText.setCharacterSize(KEY_TEXT_SIZE);
    Tracker::aText.setFillColor(sf::Color::White);
    Tracker::aText.setPosition(125, 229);

    Tracker::spaceText.setString("SPACE");
    Tracker::spaceText.setCharacterSize(KEY_TEXT_SIZE);
    Tracker::spaceText.setFillColor(sf::Color::White);
    Tracker::spaceText.setPosition(385, 340);

    Tracker::shiftText.setString("SHIFT");
    Tracker::shiftText.setCharacterSize(KEY_TEXT_SIZE);
    Tracker::shiftText.setFillColor(sf::Color::White);
    Tracker::shiftText.setPosition(125, 340);

    // Create the keys and set colors and positions
    Tracker::upKey = sf::RectangleShape(LETTER_KEY_SIZE);
    Tracker::upKey.setFillColor(sf::Color::Blue);
    Tracker::upKey.setPosition(W_KEY_POSITION);

    // Down key
    Tracker::downKey = sf::RectangleShape(LETTER_KEY_SIZE);
    Tracker::downKey.setFillColor(sf::Color::Blue);
    Tracker::downKey.setPosition(S_KEY_POSITION);

    // Right key
    Tracker::rightKey = sf::RectangleShape(LETTER_KEY_SIZE);
    Tracker::rightKey.setFillColor(sf::Color::Blue);
    Tracker::rightKey.setPosition(D_KEY_POSITION);

    // Left key
    Tracker::leftKey = sf::RectangleShape(LETTER_KEY_SIZE);
    Tracker::leftKey.setFillColor(sf::Color::Blue);
    Tracker::leftKey.setPosition(A_KEY_POSITION);

    // Space bar
    Tracker::spaceBar = sf::RectangleShape(SPACE_KEY_SIZE);
    Tracker::spaceBar.setFillColor(sf::Color::Blue);
    Tracker::spaceBar.setPosition(SPACE_KEY_POSITION);

    // Shift key
    Tracker::shiftKey = sf::RectangleShape(SHIFT_KEY_SIZE);
    Tracker::shiftKey.setFillColor(sf::Color::Blue);
    Tracker::shiftKey.setPosition(SHIFT_KEY_POSITION);

    // Mouse
    Tracker::mouseBox = sf::RectangleShape(MOUSE_BOX_SIZE);
    Tracker::mouseBox.setFillColor(sf::Color::Blue);
    Tracker::mouseBox.setPosition(MOUSE_BOX_POSITION);

    Tracker::mouseLeft = sf::RectangleShape(MOUSE_KEY_SIZE);
    Tracker::mouseLeft.setFillColor(sf::Color::Blue);
    Tracker::mouseLeft.setPosition(LEFT_MOUSE_KEY_POSITION);

    Tracker::mouseRight = sf::RectangleShape(MOUSE_KEY_SIZE);
    Tracker::mouseRight.setFillColor(sf::Color::Blue);
    Tracker::mouseRight.setPosition(RIGHT_MOUSE_KEY_POSITION);
}

void Tracker::Run() {

    while(Tracker::win.isOpen()){

        // Update everything on screen
        Tracker::Update();

        // Draw everything to the window
        Tracker::Draw();
    }
}

void Tracker::Update() {

    // Check if window is being closed
    sf::Event event;
    while(Tracker::win.pollEvent(event)){

        if(event.type == sf::Event::Closed){
            Tracker::win.close();
        }
    }

    // Check current state of keys
    if(GetAsyncKeyState('W')) {
        Tracker::upKey.setFillColor(sf::Color::White);
        Tracker::wText.setFillColor(sf::Color::Blue);
    } else {
        Tracker::upKey.setFillColor(sf::Color::Blue);
        Tracker::wText.setFillColor(sf::Color::White);
    }

    if(GetAsyncKeyState('S')) {
        Tracker::downKey.setFillColor(sf::Color::White);
        Tracker::sText.setFillColor(sf::Color::Blue);
    } else {
        Tracker::downKey.setFillColor(sf::Color::Blue);
        Tracker::sText.setFillColor(sf::Color::White);
    }

    if(GetAsyncKeyState('D')) {
        Tracker::rightKey.setFillColor(sf::Color::White);
        Tracker::dText.setFillColor(sf::Color::Blue);
    } else{
        Tracker::rightKey.setFillColor(sf::Color::Blue);
        Tracker::dText.setFillColor(sf::Color::White);
    }

    if(GetAsyncKeyState('A')) {
        Tracker::leftKey.setFillColor(sf::Color::White);
        Tracker::aText.setFillColor(sf::Color::Blue);
    }else {
        Tracker::leftKey.setFillColor(sf::Color::Blue);
        Tracker::aText.setFillColor(sf::Color::White);
    }

    if(GetAsyncKeyState(VK_SPACE)) {
        Tracker::spaceBar.setFillColor(sf::Color::White);
        Tracker::spaceText.setFillColor(sf::Color::Blue);
    } else {
        Tracker::spaceBar.setFillColor(sf::Color::Blue);
        Tracker::spaceText.setFillColor(sf::Color::White);
    }

    if(GetAsyncKeyState(VK_SHIFT)) {
        Tracker::shiftKey.setFillColor(sf::Color::White);
        Tracker::shiftText.setFillColor(sf::Color::Blue);
    } else {
        Tracker::shiftKey.setFillColor(sf::Color::Blue);
        Tracker::shiftText.setFillColor(sf::Color::White);
    }

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        Tracker::mouseLeft.setFillColor(sf::Color::White);
    } else {
        Tracker::mouseLeft.setFillColor(sf::Color::Blue);
    }

    if(sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
        Tracker::mouseRight.setFillColor(sf::Color::White);
    } else {
        Tracker::mouseRight.setFillColor(sf::Color::Blue);
    }
}

void Tracker::Draw() {

    // Draw everything to window
    Tracker::win.clear();
    Tracker::win.draw(Tracker::upKey);
    Tracker::win.draw(Tracker::downKey);
    Tracker::win.draw(Tracker::rightKey);
    Tracker::win.draw(Tracker::leftKey);
    Tracker::win.draw(Tracker::spaceBar);
    Tracker::win.draw(Tracker::shiftKey);
    Tracker::win.draw(Tracker::wText);
    Tracker::win.draw(Tracker::sText);
    Tracker::win.draw(Tracker::dText);
    Tracker::win.draw(Tracker::aText);
    Tracker::win.draw(Tracker::spaceText);
    Tracker::win.draw(Tracker::shiftText);
    Tracker::win.draw(Tracker::mouseBox);
    Tracker::win.draw(Tracker::mouseLeft);
    Tracker::win.draw(Tracker::mouseRight);
    Tracker::win.display(); // Show it
}
