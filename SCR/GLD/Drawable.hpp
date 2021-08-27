#pragma once
#include <string>
#include <vector>
#include "Vector2.hpp"

namespace gld 
{

void drawPoint(gld::Vector2f position, std::string filling, std::vector<std::vector<std::string>>& map) {
    if (position.y < 0) return;
    if (position.x < 0) return;
    if (position.y > map.size() -1)    return;
    if (position.x > map[0].size() -1) return;

    map[(int)position.y][(int)position.x] = filling;
}

void drawLine(gld::Vector2f vert1, gld::Vector2f vert2,  std::string filling, std::vector<std::vector<std::string>>& map) {
    float distX = vert1.x - vert2.x;
    float distY = vert1.y - vert2.y;

    int steps = std::abs(distX) > std::abs(distY) ? std::abs(distX) : std::abs(distY);
    steps *= 2;

    float increment_x = distX / steps;
    float increment_y = distY / steps;
        

    for (int i = 0; i < steps; i++) {
        gld::Vector2f new_pos;
        new_pos.x = vert1.x + (increment_x * i);
        new_pos.y = vert1.y + (increment_y * i);

        gld::drawPoint(new_pos, filling, map);
    }
}

enum Color {
    Default      = 49,
    Black        = 40,
    Red          = 41,
    Green        = 42,
    Yellow       = 43,
    Blue         = 44,
    Megenta      = 45,
    Cyan         = 46,
    LightGray    = 47,
    DarkGray     = 100,
    LightRed     = 101,
    LightGreen   = 102,
    LightYellow  = 103,
    LightBlue    = 104,
    LightMagenta = 105,
    LightCyan    = 106,
    White        = 107
};

class Drawable {
protected:
    std::string color = "\x1B[107m \x1B[0m";

public:
    virtual void draw(std::vector<std::vector<std::string>>& map) = 0;
    virtual void setFillColor(gld::Color color) {
        this->color = "\x1B[" + std::to_string(color) + "m \x1B[0m";
    }
};


}