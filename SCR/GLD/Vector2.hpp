#pragma once
#include <iostream>
#include <cmath>

namespace gld 
{

template<typename T>
struct Vector2 {
    T x;
    T y;

    Vector2() {
    
    }

    Vector2(T x, T y) {
        this->x = x;
        this->y = y;
    }
};

typedef Vector2<float> Vector2f;
typedef Vector2<int>   Vector2i;

}