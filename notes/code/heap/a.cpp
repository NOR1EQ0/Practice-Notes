#include <bits/stdc++.h>
#include "../tree/binary.hpp"

using namespace std;

template<typename T>
struct heap : protected ArrayBinaryTree {
public:
    int peak() {
        return this->val(0);
    }

    int push(int val) {
        return static_cast<T*>(this)._push(val);
    }
    heap(): ArrayBinaryTree({}) {};
    ~heap() = default;
    heap(const heap& obj) = default;
    heap(const heap&& obj) = default;
};

struct maxHeap : public heap<maxHeap> {
public:
private:
    int _push(int val) {
        auto retPosition = this->treePush__(val);
        auto retParent = this->parent(retPosition);
        if (retParent != numeric_limits<decltype(retParent)>::max()) {
            
        }
    }
};

int main() {
    maxHeap().push(2);
    return 0;
}