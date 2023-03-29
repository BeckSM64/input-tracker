#include <iostream>
#include <windows.h>
#include <SFML/Graphics.hpp>

#include "Tracker.h"
// #include "Key.h" // TODO: PRAGMA ONCE

Tracker::Tracker() {

    this->Setup();
    this->Run();
}

Tracker::~Tracker() {

    // Deallocate
    delete wKey;
    delete aKey;
    delete sKey;
    delete dKey;
    delete qKey;
    delete eKey;

    // Ensure nullptr
    wKey = nullptr;
    aKey = nullptr;
    sKey = nullptr;
    dKey = nullptr;
    qKey = nullptr;
    eKey = nullptr;
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
    this->win.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Input Tracker");

    // Initialize keys
    // NOTE: Keys need to be newed in order for things to not move around in memory due to issues with
    // sf::font. It seems something is being moved when these are pushed onto the stack, this fixes it.
    // There may be another solution but this seems to work.
    this->wKey = new Key(LETTER_KEY_SIZE, W_KEY_POSITION, sf::Color::Blue, "W", 50, sf::Color::White, 'W');
    this->aKey = new Key(LETTER_KEY_SIZE, A_KEY_POSITION, sf::Color::Blue, "A", 50, sf::Color::White, 'A');
    this->sKey = new Key(LETTER_KEY_SIZE, S_KEY_POSITION, sf::Color::Blue, "S", 50, sf::Color::White, 'S');
    this->dKey = new Key(LETTER_KEY_SIZE, D_KEY_POSITION, sf::Color::Blue, "D", 50, sf::Color::White, 'D');
    this->qKey = new Key(LETTER_KEY_SIZE, Q_KEY_POSITION, sf::Color::Blue, "Q", 50, sf::Color::White, 'Q');
    this->eKey = new Key(LETTER_KEY_SIZE, E_KEY_POSITION, sf::Color::Blue, "E", 50, sf::Color::White, 'E');
    this->shiftKey = new Key(SHIFT_KEY_SIZE, SHIFT_KEY_POSITION, sf::Color::Blue, "SHIFT", 50, sf::Color::White, VK_SHIFT);
    this->spaceKey = new Key(SPACE_KEY_SIZE, SPACE_KEY_POSITION, sf::Color::Blue, "SPACE", 50, sf::Color::White, VK_SPACE);
    this->mouseBox = new Key(MOUSE_BOX_SIZE, MOUSE_BOX_POSITION, sf::Color::Blue, "", 50, sf::Color::White, -1);
    this->mouseLeft = new Key(MOUSE_KEY_SIZE, LEFT_MOUSE_KEY_POSITION, sf::Color::Blue, "", 50, sf::Color::White, VK_LBUTTON);
    this->mouseRight = new Key(MOUSE_KEY_SIZE, RIGHT_MOUSE_KEY_POSITION, sf::Color::Blue, "", 50, sf::Color::White, VK_RBUTTON);
}

void Tracker::Run() {

    while(this->win.isOpen()){

        // Update everything on screen
        this->Update();

        // Draw everything to the window
        this->Draw();
    } 
}

void Tracker::Update() {

    // Check if window is being closed
    sf::Event event;
    while(this->win.pollEvent(event)){

        if(event.type == sf::Event::Closed){
            this->win.close();
        }
    }

    // Update everything on window
    this->wKey->Update();
    this->aKey->Update();
    this->sKey->Update();
    this->dKey->Update();
    this->qKey->Update();
    this->eKey->Update();
    this->shiftKey->Update();
    this->spaceKey->Update();
    this->mouseBox->Update();
    this->mouseLeft->Update();
    this->mouseRight->Update();
}

void Tracker::Draw() {

    // Draw everything to window
    this->win.clear();
    this->wKey->Draw(Tracker::win);
    this->aKey->Draw(Tracker::win);
    this->sKey->Draw(Tracker::win);
    this->dKey->Draw(Tracker::win);
    this->qKey->Draw(Tracker::win);
    this->eKey->Draw(Tracker::win);
    this->shiftKey->Draw(Tracker::win);
    this->spaceKey->Draw(Tracker::win);
    this->mouseBox->Draw(Tracker::win);
    this->mouseLeft->Draw(Tracker::win);
    this->mouseRight->Draw(Tracker::win);
    this->win.display(); // Show it
}
