#pragma once
#include <string>
#include "Vectors.hpp"
#include "Drawable.hpp"
#include "TimeImpl.hpp"

void ClearPromt();
#ifdef _WIN32 
    #define ClearPromp() system("cls");
#endif
#ifdef __unix__
    #define ClearPromp() system("clear");
#endif

namespace gld
{

class Window : public gld::Time {
private:
    unsigned int height, width;
    std::vector<std::vector<std::string>> map;

public:
    Window(gld::Vector2f size) {
        setTimeInit();

        this->height = size.y;
        this->width  = size.x;
    }

    Window(unsigned int width,unsigned int height) {
        setTimeInit();

        this->height = height;
        this->width  = width;
    }

    void clear(std::string backgroud = "\x1B[40m ") {
        map.clear();
        
        for (int y = 0; y < height; y++) {
            std::vector<std::string> new_line;
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
        setFrameInit();

        ClearPromp();

        std::string buffer;
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                buffer +=  map[y][x];
            }
            buffer += "\n";
        }

        std::cout.write(buffer.data(), buffer.size());

    }
};

}
