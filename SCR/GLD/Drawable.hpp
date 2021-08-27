#pragma once
#include <vector>
#include "Vector2.hpp"

namespace gld 
{

void drawPoint(gld::Vector2f position, char filling, std::vector<std::vector<char>>& map) {
    if (position.y < 0) return;
    if (position.x < 0) return;
    if (position.y > map.size() -1)    return;
    if (position.x > map[0].size() -1) return;

    map[(int)position.y][(int)position.x] = filling;
}

void drawLine(gld::Vector2f vert1, gld::Vector2f vert2,  char filling, std::vector<std::vector<char>>& map) {
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

class Drawable {
public:
    char filling = '@';

    virtual void draw(std::vector<std::vector<char>>& map) = 0;
    virtual void setFillChar(char filling) {
        this->filling = filling;
    }
};


}