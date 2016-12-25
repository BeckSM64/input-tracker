/**
 * Shane Harrington
 *
 * Input Tracker
 *
 * December 24, 2016
 **/

#include <SFML/Graphics.hpp>
#include <windows.h>

int main(){

    //Create the window
    sf::RenderWindow win(sf::VideoMode(500, 420), "Input Tracker");

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
        }else{
            upKey.setFillColor(sf::Color::Blue);
        }
        if(GetAsyncKeyState('S')){
            downKey.setFillColor(sf::Color::White);
        }else{
            downKey.setFillColor(sf::Color::Blue);
        }
        if(GetAsyncKeyState('D')){
            rightKey.setFillColor(sf::Color::White);
        }else{
            rightKey.setFillColor(sf::Color::Blue);
        }
        if(GetAsyncKeyState('A')){
            leftKey.setFillColor(sf::Color::White);
        }else{
            leftKey.setFillColor(sf::Color::Blue);
        }

        //Draw everything to the window
        win.clear();
        win.draw(upKey);
        win.draw(downKey);
        win.draw(rightKey);
        win.draw(leftKey);
        win.display();//Show it
    }

    return 0;
}
