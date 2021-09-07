#pragma once
#include <queue>
#include <functional>
#include <iostream>

namespace gld
{

class Key : private std::deque<char> {
public:
    using deque::operator[];

    inline Key(char a, char b = (char)0, char c = (char)0) {
        push_back(a); push_back(b); push_back(c);
    }

    inline Key(std::deque<char> deque) {
        if (deque.size() < 3) return;
        push_back(deque[0]); push_back(deque[1]); push_back(deque[2]);
    }
};

inline bool operator==(const Key& key1, const Key& key2) {
    if (key1[3] == (char)27 || key2[3] == (char)27) {
        return key1[0] == key2[0] &&
               key1[1] == key2[1] &&
               key1[2] == key2[2];
    }
    else {
        return key1[0] == key2[0];
    }
}

}
