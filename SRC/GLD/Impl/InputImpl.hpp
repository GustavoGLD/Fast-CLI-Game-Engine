#pragma once
#include <iostream>
#include <functional>

namespace gld
{

namespace Input {
    char last_key;
    std::function<void(char key)> Callback;
}

}