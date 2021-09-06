#include <iostream>
#include "GLD/GLD.hpp"

int main() {

    gld::Window window(160, 39);

    gld::Rectangle rec(50, 15);
    rec.setPosition(50, 10);
    rec.setFillColor(gld::RGB::Green);

    gld::Input::setCallback([&](char c) {
        if (c == 'd' || c == 'D') {
            rec.position = rec.position + gld::Vector2f(5.0f, 0.0f);
        }
        if (c == 'a' || c == 'A') {
            rec.position = rec.position + gld::Vector2f(-5.0f, 0.0f);
        }
        if (c == 'w' || c == 'W') {
            rec.position = rec.position + gld::Vector2f(0.0f, -2.0f);
        }
        if (c == 's' || c == 'S') {
            rec.position = rec.position + gld::Vector2f(0.0f, 2.0f);
        }
    });

    while (true) {

        window.clear();
        window.draw(rec);
        window.display(); 

    }

    return 0;
}
