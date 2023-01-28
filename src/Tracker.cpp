#include <iostream>
#include <windows.h>
#include <SFML/Graphics.hpp>

#include "Tracker.h"

Tracker::Tracker() {

    Tracker::Setup();
    Tracker::Run();
}

void Tracker::Setup() {

    // Create the window
    Tracker::win.create(sf::VideoMode(720, 520), "Input Tracker");

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
    Tracker::wText.setCharacterSize(50);
    Tracker::wText.setColor(sf::Color::White);
    Tracker::wText.setPosition(227, 119);

    Tracker::sText.setString("S");
    Tracker::sText.setCharacterSize(50);
    Tracker::sText.setColor(sf::Color::White);
    Tracker::sText.setPosition(233, 229);

    Tracker::dText.setString("D");
    Tracker::dText.setCharacterSize(50);
    Tracker::dText.setColor(sf::Color::White);
    Tracker::dText.setPosition(343, 229);

    Tracker::aText.setString("A");
    Tracker::aText.setCharacterSize(50);
    Tracker::aText.setColor(sf::Color::White);
    Tracker::aText.setPosition(125, 229);

    Tracker::spaceText.setString("SPACE");
    Tracker::spaceText.setCharacterSize(50);
    Tracker::spaceText.setColor(sf::Color::White);
    Tracker::spaceText.setPosition(385, 340);

    Tracker::shiftText.setString("SHIFT");
    Tracker::shiftText.setCharacterSize(50);
    Tracker::shiftText.setColor(sf::Color::White);
    Tracker::shiftText.setPosition(125, 340);

    // Create the keys and set colors and positions
    Tracker::upKey = sf::RectangleShape(sf::Vector2f(100, 100));
    Tracker::upKey.setFillColor(sf::Color::Blue);
    Tracker::upKey.setPosition(200, 100);

    // Down key
    Tracker::downKey = sf::RectangleShape(sf::Vector2f(100, 100));
    Tracker::downKey.setFillColor(sf::Color::Blue);
    Tracker::downKey.setPosition(200, 210);

    // Right key
    Tracker::rightKey = sf::RectangleShape(sf::Vector2f(100, 100));
    Tracker::rightKey.setFillColor(sf::Color::Blue);
    Tracker::rightKey.setPosition(310, 210);

    // Left key
    Tracker::leftKey = sf::RectangleShape(sf::Vector2f(100, 100));
    Tracker::leftKey.setFillColor(sf::Color::Blue);
    Tracker::leftKey.setPosition(90, 210);

    // Space bar
    Tracker::spaceBar = sf::RectangleShape(sf::Vector2f(320, 100));
    Tracker::spaceBar.setFillColor(sf::Color::Blue);
    Tracker::spaceBar.setPosition(310, 320);

    // Shift key
    Tracker::shiftKey = sf::RectangleShape(sf::Vector2f(210, 100));
    Tracker::shiftKey.setFillColor(sf::Color::Blue);
    Tracker::shiftKey.setPosition(90, 320);

    // Mouse
    Tracker::mouseBox = sf::RectangleShape(sf::Vector2f(210, 210));
    Tracker::mouseBox.setFillColor(sf::Color::Blue);
    Tracker::mouseBox.setPosition(420, 100);

    Tracker::mouseLeft = sf::RectangleShape(sf::Vector2f(90, 90));
    Tracker::mouseLeft.setFillColor(sf::Color::Blue);
    Tracker::mouseLeft.setPosition(430, 110);

    Tracker::mouseRight = sf::RectangleShape(sf::Vector2f(90, 90));
    Tracker::mouseRight.setFillColor(sf::Color::Blue);
    Tracker::mouseRight.setPosition(530, 110);
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
        Tracker::wText.setColor(sf::Color::Blue);
    } else {
        Tracker::upKey.setFillColor(sf::Color::Blue);
        Tracker::wText.setColor(sf::Color::White);
    }

    if(GetAsyncKeyState('S')) {
        Tracker::downKey.setFillColor(sf::Color::White);
        Tracker::sText.setColor(sf::Color::Blue);
    } else {
        Tracker::downKey.setFillColor(sf::Color::Blue);
        Tracker::sText.setColor(sf::Color::White);
    }

    if(GetAsyncKeyState('D')) {
        Tracker::rightKey.setFillColor(sf::Color::White);
        Tracker::dText.setColor(sf::Color::Blue);
    } else{
        Tracker::rightKey.setFillColor(sf::Color::Blue);
        Tracker::dText.setColor(sf::Color::White);
    }

    if(GetAsyncKeyState('A')) {
        Tracker::leftKey.setFillColor(sf::Color::White);
        Tracker::aText.setColor(sf::Color::Blue);
    }else {
        Tracker::leftKey.setFillColor(sf::Color::Blue);
        Tracker::aText.setColor(sf::Color::White);
    }

    if(GetAsyncKeyState(VK_SPACE)) {
        Tracker::spaceBar.setFillColor(sf::Color::White);
        Tracker::spaceText.setColor(sf::Color::Blue);
    } else {
        Tracker::spaceBar.setFillColor(sf::Color::Blue);
        Tracker::spaceText.setColor(sf::Color::White);
    }

    if(GetAsyncKeyState(VK_SHIFT)) {
        Tracker::shiftKey.setFillColor(sf::Color::White);
        Tracker::shiftText.setColor(sf::Color::Blue);
    } else {
        Tracker::shiftKey.setFillColor(sf::Color::Blue);
        Tracker::shiftText.setColor(sf::Color::White);
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
