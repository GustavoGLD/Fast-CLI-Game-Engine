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

    gld::Line line;
    line.setFillColor(gld::Color::Megenta);
    
    gld::Point point1;
    point1.position = {80, 0};

    gld::Point point2;
    point2.position = {0, 20};

    gld::Line line1;
    line1.vert1 = {80, 0};
    line1.vert2 = {0, 20};

    while (true) {

        //90° per seconds
        rec1.angle += 90  * window.getDeltaTime();
        rec2.angle += 180 * window.getDeltaTime();
        rec3.angle += 270 * window.getDeltaTime();
        
        line1.vert1.y = ((std::cos(window.getTime()) / 2.0f) + 0.5f) * 39;
        line1.vert2.x = ((std::sin(window.getTime()) / 2.0f) + 0.5f) * 160;

        window.clear();
        window.draw(line1);
        window.draw(rec1);
        window.draw(rec2);
        window.draw(rec3);
        window.draw(point1);
        window.draw(point2);
        window.display();
    }

    return 0;
}
