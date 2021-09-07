#pragma once
#include <string>
#include <array>

namespace gld
{

typedef std::string AnsiColor;
typedef std::array<uint8_t, 3> RgbColor;

namespace ANSI {
    const AnsiColor  Black   = "\u001b[40m ";
    const AnsiColor  Red     = "\u001b[41m ";
    const AnsiColor  Green   = "\u001b[42m ";
    const AnsiColor  Yellow  = "\u001b[43m ";
    const AnsiColor  Blue    = "\u001b[44m ";
    const AnsiColor  Magenta = "\u001b[45m ";
    const AnsiColor  Cyan    = "\u001b[46m ";
    const AnsiColor  White   = "\u001b[47m ";
};

namespace RGB {
    const RgbColor  Black   = {  0,   0,   0};
    const RgbColor  Red     = {255,   0,   0};
    const RgbColor  Green   = {  0, 255,   0};
    const RgbColor  Blue    = {  0,   0, 255};
    const RgbColor  Yellow  = {255, 255,   0};
    const RgbColor  Cyan    = {  0, 255, 255};
    const RgbColor  Magenta = {255,   0, 255};
    const RgbColor  Gray    = {129, 129, 129};
    const RgbColor  Silver  = {172, 172, 172};
};

inline gld::AnsiColor getAnsiColor(uint8_t R, uint8_t G, uint8_t B) {

    int uR = (int)R / 43;
    int uG = (int)G / 43;
    int uB = (int)B / 43;

    int uColor = 16 + (36 * uR) + (6 * uG) + uB;

    return "\x1B[48;5;" + std::to_string(uColor) + "m ";
}

inline gld::AnsiColor getAnsiColor(gld::RgbColor RGB) {
    return getAnsiColor(RGB[0], RGB[1], RGB[2]);
}

}
