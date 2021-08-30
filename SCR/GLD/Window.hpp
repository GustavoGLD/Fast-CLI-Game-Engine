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

        std::ios_base::sync_with_stdio(false);
    }

    Window(unsigned int width,unsigned int height) {
        setTimeInit();

        this->height = height;
        this->width  = width;
        
        map = std::vector<std::vector<std::string>>(height, std::vector<std::string>(width));
    }

    void clear(std::string backgroud = "\x1B[40m ") {
        
        for (int y = 0; y < height; y++) {

            for (int x = 0; x < width; x++) {
                map[y][x] = backgroud;
            }

        }
    }
    
    void draw(gld::Drawable& drawable) {
        drawable.draw(map);
    }


    void display() {
        setFrameInit();

        ClearPromp();

        std::string buffer;
        std::string last_color;

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {

                if (map[y][x] != last_color){
                       buffer += map[y][x];
                    last_color = map[y][x];
                }
                else {
                    buffer += " ";
                }

            }
            buffer += "\n";
        }

        std::cout.write(buffer.data(), buffer.size());

    }
};

}
