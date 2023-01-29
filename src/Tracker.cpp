#include <iostream>
#include <windows.h>
#include <SFML/Graphics.hpp>

#include "Tracker.h"
// #include "Key.h" // TODO: PRAGMA ONCE

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
    const sf::Vector2f Q_KEY_POSITION = sf::Vector2f(90, 100);
    const sf::Vector2f E_KEY_POSITION = sf::Vector2f(310, 100);
    const sf::Vector2f SHIFT_KEY_POSITION = sf::Vector2f(90, 320);
    const sf::Vector2f SPACE_KEY_POSITION = sf::Vector2f(310, 320);
    const sf::Vector2f MOUSE_BOX_POSITION = sf::Vector2f(420, 100);
    const sf::Vector2f LEFT_MOUSE_KEY_POSITION = sf::Vector2f(430, 110);
    const sf::Vector2f RIGHT_MOUSE_KEY_POSITION = sf::Vector2f(530, 110);

    // Create the window
    Tracker::win.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Input Tracker");

    // Initialize keys
    Tracker::wKey = Key(LETTER_KEY_SIZE, W_KEY_POSITION, sf::Color::Blue, "W", 50, sf::Color::White, 'W');
    Tracker::aKey = Key(LETTER_KEY_SIZE, A_KEY_POSITION, sf::Color::Blue, "A", 50, sf::Color::White, 'A');
    Tracker::sKey = Key(LETTER_KEY_SIZE, S_KEY_POSITION, sf::Color::Blue, "S", 50, sf::Color::White, 'S');
    Tracker::dKey = Key(LETTER_KEY_SIZE, D_KEY_POSITION, sf::Color::Blue, "D", 50, sf::Color::White, 'D');
    Tracker::qKey = Key(LETTER_KEY_SIZE, Q_KEY_POSITION, sf::Color::Blue, "Q", 50, sf::Color::White, 'Q');
    Tracker::eKey = Key(LETTER_KEY_SIZE, E_KEY_POSITION, sf::Color::Blue, "E", 50, sf::Color::White, 'E');
    Tracker::shiftKey = Key(SHIFT_KEY_SIZE, SHIFT_KEY_POSITION, sf::Color::Blue, "SHIFT", 50, sf::Color::White, VK_SHIFT);
    Tracker::spaceKey = Key(SPACE_KEY_SIZE, SPACE_KEY_POSITION, sf::Color::Blue, "SPACE", 50, sf::Color::White, VK_SPACE);
    Tracker::mouseBox = Key(MOUSE_BOX_SIZE, MOUSE_BOX_POSITION, sf::Color::Blue, "", 50, sf::Color::White, -1);
    Tracker::mouseLeft = Key(MOUSE_KEY_SIZE, LEFT_MOUSE_KEY_POSITION, sf::Color::Blue, "", 50, sf::Color::White, VK_LBUTTON);
    Tracker::mouseRight = Key(MOUSE_KEY_SIZE, RIGHT_MOUSE_KEY_POSITION, sf::Color::Blue, "", 50, sf::Color::White, VK_RBUTTON);
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

    // Update everything on window
    Tracker::wKey.Update();
    Tracker::aKey.Update();
    Tracker::sKey.Update();
    Tracker::dKey.Update();
    Tracker::qKey.Update();
    Tracker::eKey.Update();
    Tracker::shiftKey.Update();
    Tracker::spaceKey.Update();
    Tracker::mouseBox.Update();
    Tracker::mouseLeft.Update();
    Tracker::mouseRight.Update();
}

void Tracker::Draw() {

    // Draw everything to window
    Tracker::win.clear();
    Tracker::wKey.Draw(Tracker::win);
    Tracker::aKey.Draw(Tracker::win);
    Tracker::sKey.Draw(Tracker::win);
    Tracker::dKey.Draw(Tracker::win);
    Tracker::qKey.Draw(Tracker::win);
    Tracker::eKey.Draw(Tracker::win);
    Tracker::shiftKey.Draw(Tracker::win);
    Tracker::spaceKey.Draw(Tracker::win);
    Tracker::mouseBox.Draw(Tracker::win);
    Tracker::mouseLeft.Draw(Tracker::win);
    Tracker::mouseRight.Draw(Tracker::win);
    Tracker::win.display(); // Show it
}
