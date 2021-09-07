#pragma once
#include <queue>

namespace gld
{

class Key : private std::deque<char> {
public:
    using deque::operator[];

    inline Key(char a, char b = (char)0, char c = (char)0) {
        push_front(a); push_front(b); push_front(c);
    }

    inline Key(std::deque<char> deque) {
        if (deque.size() < 3) return;
        push_front(deque[0]); push_front(deque[1]); push_front(deque[2]);
    }
};

}
