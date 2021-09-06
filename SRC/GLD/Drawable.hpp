#pragma once
#include <string>
#include <array>

#include "Impl/DrawableImpl.hpp"
#include "Colors.hpp"

namespace gld 
{

class Drawable {
protected:
    gld::AnsiColor color = gld::ANSI::White;

public:
    virtual void draw(std::vector<std::vector<std::string>>& map) = 0;

    inline void setFillColor(uint8_t R, uint8_t G, uint8_t B) {
        color = gld::getAnsiColor(R, G, B);
    }

    inline void setFillColor(const gld::RgbColor& RGB) {
        color = gld::getAnsiColor(RGB);
    }

};


}