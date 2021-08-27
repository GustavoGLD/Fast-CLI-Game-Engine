#pragma once
#include "Vector2.hpp"
#include "Drawable.hpp"

namespace gld 
{

class Line : public gld::Drawable {
public:
    gld::Vector2f vert1, vert2;

    void draw(std::vector<std::vector<char>>& map) {
        float distX = std::abs(vert1.x - vert2.x);
        float distY = std::abs(vert1.y - vert2.y);

        int steps = distX > distY ? distX : distY;

        float increment_x = distX / steps;
        float increment_y = distY / steps;
        

        for (int i = 0; i < steps; i++) {
            gld::Vector2f new_pos;
            new_pos.x = vert1.x + (increment_x * i);
            new_pos.y = vert1.y + (increment_y * i);

            gld::drawPoint(new_pos, filling, map);
        }
    }

};

}
