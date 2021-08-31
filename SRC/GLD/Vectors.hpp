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
inline Vector2<T> operator+(Vector2<T> vec1, Vector2<T> vec2) {
    Vector2<T> sum;
    sum.x = vec1.x + vec2.x;
    sum.y = vec1.y + vec2.y;
    return sum;
}

template<typename T>
inline Vector2<T> operator-(Vector2<T> vec1, Vector2<T> vec2) {
    Vector2<T> sub;
    sub.x = vec1.x - vec2.x;
    sub.y = vec1.y - vec2.y;
    return sub;
}

template<typename T>
inline Vector2<T> operator*(Vector2<T> vec, T n) {
    Vector2<T> mult;
    mult.x = vec.x * n;
    mult.y = vec.y * n;
    return mult;
}

template<typename T>
inline Vector2<T> operator/(Vector2<T> vec, T n) {
    Vector2<T> div;
    div.x = vec.x / n;
    div.y = vec.y / n;
    return div;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const gld::Vector2<T> vector) {
    os << "x:[" << vector.x << "], y:[" << vector.y << "].";
    return os;
}

};
