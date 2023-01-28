#include <SFML/Graphics.hpp>

#include "Key.h"

class Tracker {

    public:

        Tracker();

    private:

        void Setup();
        void Run();
        void Update();
        void Draw();

        // Window
        sf::RenderWindow win;

        // Font
        sf::Font font;

        // Text
        sf::Text wText;
        sf::Text aText;
        sf::Text sText;
        sf::Text dText;
        sf::Text qText;
        sf::Text eText;
        sf::Text spaceText;
        sf::Text shiftText;

        // Keys
        sf::RectangleShape upKey;
        sf::RectangleShape downKey;
        sf::RectangleShape rightKey;
        sf::RectangleShape leftKey;
        sf::RectangleShape qKey;
        sf::RectangleShape eKey;
        sf::RectangleShape spaceBar;
        sf::RectangleShape shiftKey;
        sf::RectangleShape mouseBox;
        sf::RectangleShape mouseLeft;
        sf::RectangleShape mouseRight;

        Key testKey;
};