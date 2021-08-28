#pragma once
#include <iostream>
#include <cmath>

namespace gld 
{

template<typename T>
struct Vector2 {
    T x, y;

    Vector2() {
        x = NULL;
        y = NULL;
    }

    Vector2(T x, T y) {
        this->x = x;
        this->y = y;
    }
};

typedef Vector2<float> Vector2f;
typedef Vector2<int>   Vector2i;

template<typename T>
struct Vector3 {
    T x, y, z;

    Vector3() {
        x = NULL;
        y = NULL;
        z = NULL;
    }

    Vector3(T x, T y, T z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

typedef Vector3<float> Vector3f;
typedef Vector3<int>   Vector3i;

}