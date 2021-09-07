#pragma once
#include <iostream>
#include <functional>
#include <queue>
#include "../Keyboard.hpp"

namespace gld {
    namespace Input {
        std::deque<char> lastkeys(3, (char)0);
        std::function<void(Key key)> Callback;
    }
}


void getInput();

#if defined(_WIN32) || defined(_WIN64)

    void getInput() {
        //coming soon
    }

#endif

#if defined(__linux__) || defined(__FreeBSD__)

    using namespace gld;

    void getInput(){
        system("stty raw");

        while(true) {

            char last_key = getchar();

            Input::lastkeys.push_back(last_key);
            Input::lastkeys.pop_front();

            Input::Callback(Input::lastkeys);

            if(last_key == '.') {
                system("stty cooked");
                exit(0);
            }
        }
    }

#endif
