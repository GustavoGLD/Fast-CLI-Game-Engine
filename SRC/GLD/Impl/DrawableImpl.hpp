#pragma once
#include <string>
#include <vector>
#include <functional>
#include "../Vectors.hpp"

namespace gld 
{



class MakingLine {
public:
    gld::Vector2f A, B;
    gld::Vector2f dist;
    gld::Vector2f incr;
    gld::Vector2f next_pos;
    int steps;

    MakingLine(gld::Vector2f A, gld::Vector2f B) {
        this->A = A;
        this->B = B;

        dist.x = B.x - A.x;
        dist.y = B.y - A.y;
        
        steps = std::abs(dist.x) > std::abs(dist.y) ? std::abs(dist.x) : std::abs(dist.y);

        incr.x = dist.x / steps;
        incr.y = dist.y / steps;
    }

    inline void callMakingLine(std::function<void()> callback) {
    
        for (int s = 0; s < steps; s++) {
            next_pos.x = A.x + (incr.x * s);
            next_pos.y = A.y + (incr.y * s);

            callback();
        }
    }

    inline void setSteps(int steps) {
        this->steps = steps;

        incr.x = dist.x / steps;
        incr.y = dist.y / steps;
    }

    inline void updateNextPos() {
        next_pos = next_pos + incr;
    }

};

void drawPoint(gld::Vector2f position, std::string filling, std::vector<std::vector<std::string>>& map) {
    if (position.y < 0) return;
    if (position.x < 0) return;
    if (position.y > map.size() -1)    return;
    if (position.x > map[0].size() -1) return;

    map[(int)position.y][(int)position.x] = filling;
}

void drawLine(gld::Vector2f vert1, gld::Vector2f vert2,  std::string color, std::vector<std::vector<std::string>>& map) {

    gld::MakingLine line(vert1, vert2);

    line.callMakingLine([&](){
        gld::drawPoint(line.next_pos, color, map);
    });
}

struct Color {
    uint8_t R = 255, G = 255, B = 255;

    Color(uint8_t R, uint8_t G, uint8_t B) {
        this->R = R; this->G = G; this->B;
    }

};

namespace getColor {
    const Color Red     = {255, 0, 0};
    const Color Green   = {0, 255, 0};
    const Color Blue    = {0, 0, 255};
    const Color Yellow  = {255, 255, 0};
    const Color Cyan    = {0, 255, 255};
    const Color Magenta = {255, 0, 255};
    const Color Gray    = {129, 129, 129};
    const Color Silver  = {172, 172, 172};
}


}