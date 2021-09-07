#pragma once
#include <string>
#include <thread>
#include "Vectors.hpp"
#include "Drawable.hpp"
#include "Impl/TimeImpl.hpp"
#include "Impl/InputImpl.hpp"
#include "Colors.hpp"
#include "Input.hpp"

#if defined(_WIN32) || defined(_WIN64)
    #define ClearPrompt() system("cls");
#endif
#if defined(__linux__) || defined(__FreeBSD__)
    #define ClearPrompt() system("clear");
#endif

namespace gld
{

class Window : public gld::Time {
private:
    unsigned int height, width;
    std::vector<std::vector<std::string>> map;
    std::thread input_thr;

public:

    inline Window(unsigned int width,unsigned int height, bool sync_with_stdio = false) {
        setTimeInit();

        this->height = height;
        this->width  = width;

        std::ios_base::sync_with_stdio(sync_with_stdio);
        map = std::vector<std::vector<std::string>>(height, std::vector<std::string>(width));
        input_thr = std::thread(Input::getInput);
    }

    inline void clear(gld::AnsiColor backgroud = gld::ANSI::Black) {

        for (int y = 0; y < height; y++) {

            for (int x = 0; x < width; x++) {
                map[y][x] = backgroud;
            }

        }
    }

    inline void clear(gld::RgbColor background) {
        clear(gld::getAnsiColor(background));
    }

    inline void clear(uint8_t R, uint8_t G, uint8_t B) {
        clear(gld::getAnsiColor(R, G, B));
    }

    inline void draw(gld::Drawable& drawable) {
        drawable.draw(map);
    }


    inline void display() {
        setFrameInit();

        ClearPrompt();

        std::string    buffer;
        gld::AnsiColor last_color;

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
            buffer += "\r\n";
        }

        std::cout.write(buffer.data(), buffer.size());

    }
};

}
