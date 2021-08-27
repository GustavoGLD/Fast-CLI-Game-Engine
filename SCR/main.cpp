#include <iostream>
#include "GLD/GLD.hpp"

int main() {

    gld::Window window(40, 160);
    gld::Rectangle rectangle(30, 15);
    rectangle.position.x = 50;
    rectangle.position.y = 15;

    while (true) {
        rectangle.angle += 0.5;

        window.clear();
        window.draw(rectangle);
        window.display();
    }

    return 0;
}
