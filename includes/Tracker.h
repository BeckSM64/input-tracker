#include <SFML/Graphics.hpp>

#include "Key.h"

class Tracker {

    public:

        Tracker();
        ~Tracker();

    private:

        void Setup();
        void Run();
        void Update();
        void Draw();

        // Window
        sf::RenderWindow win;

        // Font
        sf::Font font;

        // Keys
        Key *wKey;
        Key *aKey;
        Key *sKey;
        Key *dKey;
        Key *qKey;
        Key *eKey;
        Key *shiftKey;
        Key *spaceKey;
        Key *mouseBox;
        Key *mouseLeft;
        Key *mouseRight;
};