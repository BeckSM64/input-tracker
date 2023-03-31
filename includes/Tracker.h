#include <SFML/Graphics.hpp>

#include "Key.h"
#include "KeyboardKey.h"
#include "MouseKey.h"

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
        KeyboardKey *wKey;
        KeyboardKey *aKey;
        KeyboardKey *sKey;
        KeyboardKey *dKey;
        KeyboardKey *qKey;
        KeyboardKey *eKey;
        KeyboardKey *shiftKey;
        KeyboardKey *spaceKey;
        Key *mouseBox;
        MouseKey *mouseLeft;
        MouseKey *mouseRight;
};