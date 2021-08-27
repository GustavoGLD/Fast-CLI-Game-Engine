#include <iostream>
#include "GLD/GLD.hpp"

int main() {

    gld::Window window(160, 40);
    
    gld::Rectangle rec1(30, 15);
    rec1.setPosition(50, 18);
    rec1.setFillColor(gld::Color::Blue);

    gld::Rectangle rec2(20, 10);
    rec2.setPosition(80, 13);
    rec2.setFillColor(gld::Color::Green);

    gld::Rectangle rec3(24, 12);
    rec3.setPosition(120, 23);
    rec3.setFillColor(gld::Color::Red);

    while (true) {

        //90° per seconds
        rec1.angle += 90  * window.getDeltaTime();
        rec2.angle += 270 * window.getDeltaTime();
        rec3.angle += 180 * window.getDeltaTime();


        window.clear();
        window.draw(rec1);
        window.draw(rec2);
        window.draw(rec3);
        window.display();

        std::cout << "FPS: " << 1 / window.getDeltaTime() << "\n";
    }

    return 0;
}
