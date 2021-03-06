#pragma once
#include "Vectors.hpp"
#include "Drawable.hpp"

namespace gld
{

class Point : public gld::Drawable {
public:
    gld::Vector2f position;

    void draw(std::vector<std::vector<std::string>>& map) {
        if (position.y < 0) return;
        if (position.x < 0) return;
        if (position.y > map.size() -1)    return;
        if (position.x > map[0].size() -1) return;

        map[(int)position.y][(int)position.x] = color;
    }
    
    Point() {
        //nothing
    }

    Point(gld::Vector2f position) {
        this->position = position;
    }

    Point(float posX, float posY) {
        position.x = posX;
        position.y = posY;
    }
};

}
