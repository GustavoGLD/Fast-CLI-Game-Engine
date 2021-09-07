#include <iostream>
#include "GLD/GLD.hpp"

int main() {

    gld::Window window(160, 39);

    gld::Rectangle rec(50, 15);
    rec.setPosition(50, 10);
    rec.setFillColor(gld::RGB::Green);

    gld::Input::setCallback([&](gld::Key c) {
        if (c[0] == 'd' || c[0] == 'D') {
            rec.position = rec.position + gld::Vector2f(5.0f, 0.0f);
        }
        if (c[0] == 'a' || c[0] == 'A') {
            rec.position = rec.position + gld::Vector2f(-5.0f, 0.0f);
        }
        if (c[0] == 'w' || c[0] == 'W') {
            rec.position = rec.position + gld::Vector2f(0.0f, -2.0f);
        }
        if (c[0] == 's' || c[0] == 'S') {
            rec.position = rec.position + gld::Vector2f(0.0f, 2.0f);
        }

        std::cout << "\n";
        for (int x = 0; x < 3; x++) {
            std::cout << (int)c[x] << "\t";
        }

    });

    while (true) {

        window.clear();
        window.draw(rec);
        //window.display();

    }

    return 0;
}
