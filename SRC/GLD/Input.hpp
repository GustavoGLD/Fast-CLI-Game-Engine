#pragma once
#include <iostream>
#include <functional>
#include "Keyboard.hpp"


namespace gld
{

namespace Input {

    #include "Impl/InputImpl.hpp"

    void setCallback(std::function<void(Key key)> Inputs_Callback) {
        gld::Input::Callback = Inputs_Callback;
    }

}

}
