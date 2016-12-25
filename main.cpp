/**
 * Shane Harrington
 *
 * Input Tracker
 *
 * December 24, 2016
 **/

#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>

using namespace std;

int main(){

    //Create the window
    sf::RenderWindow win(sf::VideoMode(500, 420), "Input Tracker");

    //Create text for keys
    sf::Text wText;
    sf::Text sText;
    sf::Text aText;
    sf::Text dText;

    //Load font
    sf::Font font;
    if(!font.loadFromFile("fonts/arial.ttf")){
        cout << "Error loading font" << endl;
    }

    //Set fonts
    wText.setFont(font);
    sText.setFont(font);
    dText.setFont(font);
    aText.setFont(font);

    //Create texts
    wText.setString("W");
    wText.setCharacterSize(50);
    wText.setColor(sf::Color::White);
    wText.setPosition(227, 119);

    sText.setString("S");
    sText.setCharacterSize(50);
    sText.setColor(sf::Color::White);
    sText.setPosition(233, 229);

    dText.setString("D");
    dText.setCharacterSize(50);
    dText.setColor(sf::Color::White);
    dText.setPosition(343, 229);

    aText.setString("A");
    aText.setCharacterSize(50);
    aText.setColor(sf::Color::White);
    aText.setPosition(125, 229);

    //Create the arrow keys, which are represented by rectangles
    //Up key
    sf::RectangleShape upKey(sf::Vector2f(100, 100));
    upKey.setFillColor(sf::Color::Blue);
    upKey.setPosition(200, 100);

    //Down key
    sf::RectangleShape downKey(sf::Vector2f(100, 100));
    downKey.setFillColor(sf::Color::Blue);
    downKey.setPosition(200, 210);

    //Right key
    sf::RectangleShape rightKey(sf::Vector2f(100, 100));
    rightKey.setFillColor(sf::Color::Blue);
    rightKey.setPosition(310, 210);

    //Left key
    sf::RectangleShape leftKey(sf::Vector2f(100, 100));
    leftKey.setFillColor(sf::Color::Blue);
    leftKey.setPosition(90, 210);

    while(win.isOpen()){

        sf::Event event;
        while(win.pollEvent(event)){

            if(event.type == sf::Event::Closed){
                win.close();
            }
        }

        //Check current state of keys
        if(GetAsyncKeyState('W')){
            upKey.setFillColor(sf::Color::White);
            wText.setColor(sf::Color::Blue);
        }else{
            upKey.setFillColor(sf::Color::Blue);
            wText.setColor(sf::Color::White);
        }
        if(GetAsyncKeyState('S')){
            downKey.setFillColor(sf::Color::White);
            sText.setColor(sf::Color::Blue);
        }else{
            downKey.setFillColor(sf::Color::Blue);
            sText.setColor(sf::Color::White);
        }
        if(GetAsyncKeyState('D')){
            rightKey.setFillColor(sf::Color::White);
            dText.setColor(sf::Color::Blue);
        }else{
            rightKey.setFillColor(sf::Color::Blue);
            dText.setColor(sf::Color::White);
        }
        if(GetAsyncKeyState('A')){
            leftKey.setFillColor(sf::Color::White);
            aText.setColor(sf::Color::Blue);
        }else{
            leftKey.setFillColor(sf::Color::Blue);
            aText.setColor(sf::Color::White);
        }

        //Draw everything to the window
        win.clear();
        win.draw(upKey);
        win.draw(downKey);
        win.draw(rightKey);
        win.draw(leftKey);
        win.draw(wText);
        win.draw(sText);
        win.draw(dText);
        win.draw(aText);
        win.display();//Show it
    }

    return 0;
}
