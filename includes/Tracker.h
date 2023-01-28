#include <SFML/Graphics.hpp>

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
        sf::Text sText;
        sf::Text aText;
        sf::Text dText;
        sf::Text spaceText;
        sf::Text shiftText;

        // Keys
        sf::RectangleShape upKey;
        sf::RectangleShape downKey;
        sf::RectangleShape rightKey;
        sf::RectangleShape leftKey;
        sf::RectangleShape spaceBar;
        sf::RectangleShape shiftKey;
        sf::RectangleShape mouseBox;
        sf::RectangleShape mouseLeft;
        sf::RectangleShape mouseRight;
};