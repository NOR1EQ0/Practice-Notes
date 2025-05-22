#include <bits/stdc++.h>
#include "../tree/binary.hpp"

using namespace std;

struct maxHeap: ArrayBinaryTree {
public:
    int peak() {
        return this->val(0);
    }
    
    int push(int val) {
        // TODO
    }
};

int main() {
    return 0;
}