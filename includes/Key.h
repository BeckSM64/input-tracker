#include <SFML/Graphics.hpp>

class Key {

    public:

        Key();
        Key(const sf::Vector2f KEY_SIZE,
            const sf::Vector2f KEY_POSITION,
            const sf::Color KEY_COLOR,
            const std::string TEXT_STRING,
            const int TEXT_SIZE,
            const sf::Vector2f TEXT_POSITION,
            sf::Color textColor);
        void Update();
        void Draw(sf::RenderWindow &win);

    private:

        // Key font
        sf::Font font;

        // Key text
        sf::Text keyText;

        // Key shape
        sf::RectangleShape keyShape;

};
