#include <iostream>
#include "GLD/GLD.hpp"

int main() {

    gld::Window window(160, 39);

    gld::Rectangle rec(50, 15);
    rec.setPosition(50, 10);
    rec.setFillColor(gld::RGB::Green);

    gld::Input::setCallback([&](gld::Key c) {
        gld::Key up    = {(char)65, (char)91, (char)27};
        gld::Key right = {(char)67, (char)91, (char)27};
        gld::Key down  = {(char)66, (char)91, (char)27};
        gld::Key left  = {(char)68, (char)91, (char)27};
        
        //this below is ugly, made just for testing
        
        if (c == right) {
            rec.position = rec.position + gld::Vector2f(5.0f, 0.0f);
        }
        if (c == left) {
            rec.position = rec.position + gld::Vector2f(-5.0f, 0.0f);
        }
        if (c == up) {
            rec.position = rec.position + gld::Vector2f(0.0f, -2.0f);
        }
        if (c == down) {
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
