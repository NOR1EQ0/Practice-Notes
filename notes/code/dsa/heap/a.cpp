#include <bits/stdc++.h>
#include "../tree/binary.hpp"

using namespace std;

template<typename T>
struct heap : protected ArrayBinaryTree {
public:
    int peak() {
        return this->val(0);
    }
    heap(vector<int> vec) : ArrayBinaryTree(vec) {};
    ~heap() = default;
    heap(const heap& obj) = default;
    heap(heap&& obj) = default;
};

struct maxHeap : public heap<maxHeap> {
public:
    int push(int val) {
        auto retPosition = this->treePush__(val);
        auto retParent = this->parent(retPosition);
        decltype(retPosition) ret = 0;
        // Heapify
        while (retParent != numeric_limits<decltype(retParent)>::max()) {
            if (this->val(retParent) < this->val(retPosition)) {
                swap(this->tree_[retParent], this->tree_[retPosition]);
            } else {
                if (ret == 0)
                    ret = retPosition;
            }
            retPosition = retParent;
            retParent = this->parent(retPosition);
        }
        return ret;
    }

    void pop() {
        if (this->tree_.empty()) return;
        swap(this->tree_.back(), this->tree_.front());
        this->treePop__();
        size_t curParent = 0;
        while (true) {
            auto leftpos = this->left(curParent), rightpos = this->right(curParent);
            if (leftpos == numeric_limits<decltype(leftpos)>::max() and rightpos == numeric_limits<decltype(rightpos)>::max()) break;

            auto leftv = leftpos != numeric_limits<decltype(leftpos)>::max() ? this->val(leftpos) : numeric_limits<int>::min(),
                rightv = rightpos != numeric_limits<decltype(rightpos)>::max() ? this->val(rightpos) : numeric_limits<int>::min();
            int value[3] = { this->val(curParent), leftv, rightv };
            size_t pos[3] = { curParent, leftpos, rightpos };
            auto elem = max_element(value, value + 3);
            auto maxpos = *(pos + (elem - value));
            if (maxpos == curParent) break;
            swap(this->tree_[maxpos], this->tree_[curParent]);
            curParent = maxpos;
        }
    }
};

int main() {
    vector<int> inputVec = {
        /* holder */
        9,8,6,6,7,5,2,1,4,3,6,2
    };
    vector<int> input2 = {
        9,8,7,6,7,6,2,1,4,3,6,2,5
    };
    maxHeap heap1(inputVec);
    maxHeap heap2(input2);
    cout << heap1.push(7) << endl;
    heap2.pop();
    return 0;
}