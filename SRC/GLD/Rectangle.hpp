#pragma once
#include <string>
#include "Vectors.hpp"
#include "Drawable.hpp"

namespace gld 
{


class Rectangle : public gld::Drawable {
public:
    gld::Vector2f position, size;
    
    float angle = 0.0f;
    
    inline Rectangle() {
        position = gld::Vector2f(0.0f, 0.0f);
    }

    inline Rectangle(gld::Vector2f size) {
        this->size = size;
    }
    
    inline Rectangle(float width, float height) {
        this->size = gld::Vector2f(width, height);
    }

    inline void setPosition(gld::Vector2f position) {
        this->position = position;
    }

    inline void setPosition(float x, float y) {
        this->position = {x, y};
    }

    inline void draw(std::vector<std::vector<std::string>>& map) {
        float distX = std::sin(angle * M_PI/180.0f) * size.y;
        float distY = std::cos(angle * M_PI/180.0f) * size.y;


        int steps = std::abs(distX) > std::abs(distY) ? std::abs(distX) : std::abs(distY);
        steps *= 1.5;

        float increment_x =  distX / steps;
        float increment_y = (distY / steps) / 2.5;

        float incr_vet_x =  std::cos(angle * M_PI/180.0f) * size.x;
        float incr_vet_y = (std::sin(angle * M_PI/180.0f) * size.x) / 2.5;
    
        for (int i = 0; i < steps; i++) {
            gld::Vector2f ray, rayDir;
            ray.x = position.x + (increment_x * i);
            ray.y = position.y + (increment_y * i);
            
            rayDir.x = ray.x + incr_vet_x;
            rayDir.y = ray.y - incr_vet_y;

            gld::drawLine(ray, rayDir, color, map);
        }       
    }
};


} 