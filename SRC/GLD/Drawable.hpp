#pragma once
#include <string>

#include "Impl/DrawableImpl.hpp"

namespace gld 
{

class Drawable {
protected:
    std::string color = "\x1B[41m ";

public:
    virtual void draw(std::vector<std::vector<std::string>>& map) = 0;

    void setFillColor(uint8_t R, uint8_t G, uint8_t B) {

        int uR = (int)R / 43; 
        int uG = (int)G / 43; 
        int uB = (int)B / 43;

        int uColor = 16 + (36 * uR) + (6 * uG) + uB;

        this->color = "\x1B[48;5;" + std::to_string(uColor) + "m ";
    }

    inline void setFillColor(const gld::Color& color) {
        setFillColor(color.R, color.G, color.B);
    }
};


}