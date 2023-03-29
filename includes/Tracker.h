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
        Key *wKey = nullptr;
        Key *aKey = nullptr;
        Key *sKey = nullptr;
        Key *dKey = nullptr;
        Key *qKey = nullptr;
        Key *eKey = nullptr;
        Key *shiftKey = nullptr;
        Key *spaceKey = nullptr;
        Key *mouseBox = nullptr;
        Key *mouseLeft = nullptr;
        Key *mouseRight = nullptr;
};