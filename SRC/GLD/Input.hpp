#pragma once
#include <iostream>
#include <functional>


namespace gld
{

namespace Input {

    #include "Impl/InputImpl.hpp"

    char getLastKey() {
        return gld::Input::last_key;
    }

    void setCallback(std::function<void(char key)> Inputs_Callback) {
        gld::Input::Callback = Inputs_Callback;
    }



    std::function<void(char key)>& __getCallback() {
        return gld::Input::Callback;
    }

    void __setLastKey(char key) {
        gld::Input::last_key = key;
    }
}

}


void getInput();

#if defined(_WIN32) || defined(_WIN64)
    
    void getInput() {
        //coming soon
    }

#endif

#if defined(__linux__) || defined(__FreeBSD__)

    void getInput(){
        system("stty raw");

        while(true) {

            gld::Input::__setLastKey(getchar());

            gld::Input::__getCallback()(gld::Input::getLastKey());

            if(gld::Input::getLastKey() == '.') {
                system("stty cooked");
                exit(0);
            }  
        }
    }

#endif

