#pragma once
#include "Vector2.hpp"
#include "Drawable.hpp"

namespace gld
{

class Window {
private:
    unsigned int height, width;
public:
    std::vector<std::vector<char>> map;

public:
    Window(gld::Vector2f size) {
        this->height = size.y;
        this->width  = size.x;
    }

    Window(unsigned int height,unsigned int width) {
        this->height = height;
        this->width  = width;
    }

    void clear(char backgroud = '.') {
        map.clear();

        for (int y = 0; y < height; y++) {
            std::vector<char> new_line;
            for (int x = 0; x < width; x++) {
                new_line.push_back(backgroud);
            }
            map.push_back(new_line);
        }
    }
    
    void draw(gld::Drawable& drawable) {
        drawable.draw(map);
    }

    void display() {
        system("clear");
        std::string buffer;
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                buffer +=  map[y][x];
                //buffer += ' ';
            }
            buffer += "\n";
        }

        printf("%s", buffer.c_str());
    }
};

}
