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
    sf::RenderWindow win(sf::VideoMode(720, 520), "Input Tracker");

    //Create text for keys
    sf::Text wText;
    sf::Text sText;
    sf::Text aText;
    sf::Text dText;
    sf::Text spaceText;
    sf::Text shiftText;

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
    spaceText.setFont(font);
    shiftText.setFont(font);

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

    spaceText.setString("SPACE");
    spaceText.setCharacterSize(50);
    spaceText.setColor(sf::Color::White);
    spaceText.setPosition(385, 340);

    shiftText.setString("SHIFT");
    shiftText.setCharacterSize(50);
    shiftText.setColor(sf::Color::White);
    shiftText.setPosition(125, 340);

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

    //Space bar
    sf::RectangleShape spaceBar(sf::Vector2f(320, 100));
    spaceBar.setFillColor(sf::Color::Blue);
    spaceBar.setPosition(310, 320);

    //Shift key
    sf::RectangleShape shiftKey(sf::Vector2f(210, 100));
    shiftKey.setFillColor(sf::Color::Blue);
    shiftKey.setPosition(90, 320);

    //Mouse
    sf::RectangleShape mouseBox(sf::Vector2f(210, 210));
    mouseBox.setFillColor(sf::Color::Blue);
    mouseBox.setPosition(420, 100);

    sf::RectangleShape mouseLeft(sf::Vector2f(90, 90));
    mouseLeft.setFillColor(sf::Color::Blue);
    mouseLeft.setPosition(430, 110);

    sf::RectangleShape mouseRight(sf::Vector2f(90, 90));
    mouseRight.setFillColor(sf::Color::Blue);
    mouseRight.setPosition(530, 110);

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
        if(GetAsyncKeyState(VK_SPACE)){
            spaceBar.setFillColor(sf::Color::White);
            spaceText.setColor(sf::Color::Blue);
        }else{
            spaceBar.setFillColor(sf::Color::Blue);
            spaceText.setColor(sf::Color::White);
        }
        if(GetAsyncKeyState(VK_SHIFT)){
            shiftKey.setFillColor(sf::Color::White);
            shiftText.setColor(sf::Color::Blue);
        }else{
            shiftKey.setFillColor(sf::Color::Blue);
            shiftText.setColor(sf::Color::White);
        }
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            mouseLeft.setFillColor(sf::Color::White);
        }
        else{
            mouseLeft.setFillColor(sf::Color::Blue);
        }
        if(sf::Mouse::isButtonPressed(sf::Mouse::Right)){
            mouseRight.setFillColor(sf::Color::White);
        }
        else{
            mouseRight.setFillColor(sf::Color::Blue);
        }

        //Draw everything to the window
        win.clear();
        win.draw(upKey);
        win.draw(downKey);
        win.draw(rightKey);
        win.draw(leftKey);
        win.draw(spaceBar);
        win.draw(shiftKey);
        win.draw(wText);
        win.draw(sText);
        win.draw(dText);
        win.draw(aText);
        win.draw(spaceText);
        win.draw(shiftText);
        win.draw(mouseBox);
        win.draw(mouseLeft);
        win.draw(mouseRight);
        win.display();//Show it
    }

    return 0;
}
