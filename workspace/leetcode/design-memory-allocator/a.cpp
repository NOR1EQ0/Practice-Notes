#include <bits/stdc++.h>

using namespace std;

class Allocator {
public:
    Allocator(int n) {
        this->mem = new int[n]();
    }

    int allocate(int size, int mID) {
        int position = -1;
        int free_mem = 0;
        bool exit = false;
        for (int i = 0; (i < n); ++i) {
            if (!(this->mem[i])) {
                position = i;
                for (int j = i; j < n; ++j) {
                    if (free_mem >= size) {
                        break;
                    }
                }
            }
            if (exit) break;
        }
        return position;
    }

    int freeMemory(int mID) {
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (mem[i] == mID) {
                mem[i] = 0;
                cnt++;
            }
        }
        return cnt;
    }

    ~Allocator() {
        delete[] mem;
        
    }
private:
    int n = 0;
    int* mem = nullptr;
};



/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */

int main() {
    Allocator loc(10); // 初始化一个大小为 10 的内存数组，所有内存单元都是空闲的。
    loc.allocate(1, 1); // 最左侧的块的第一个下标是 0 。内存数组变为 [1, , , , , , , , , ]。返回 0 。
    loc.allocate(1, 2); // 最左侧的块的第一个下标是 1 。内存数组变为 [1,2, , , , , , , , ]。返回 1 。
    loc.allocate(1, 3); // 最左侧的块的第一个下标是 2 。内存数组变为 [1,2,3, , , , , , , ]。返回 2 。
    loc.freeMemory(2); // 释放 mID 为 2 的所有内存单元。内存数组变为 [1, ,3, , , , , , , ] 。返回 1 ，因为只有 1 个 mID 为 2 的内存单元。
    loc.allocate(3, 4); // 最左侧的块的第一个下标是 3 。内存数组变为 [1, ,3,4,4,4, , , , ]。返回 3 。
    loc.allocate(1, 1); // 最左侧的块的第一个下标是 1 。内存数组变为 [1,1,3,4,4,4, , , , ]。返回 1 。
    loc.allocate(1, 1); // 最左侧的块的第一个下标是 6 。内存数组变为 [1,1,3,4,4,4,1, , , ]。返回 6 。
    loc.freeMemory(1); // 释放 mID 为 1 的所有内存单元。内存数组变为 [ , ,3,4,4,4, , , , ] 。返回 3 ，因为有 3 个 mID 为 1 的内存单元。
    loc.allocate(10, 2); // 无法找出长度为 10 个连续空闲内存单元的空闲块，所有返回 -1 。
    loc.freeMemory(7); // 释放 mID 为 7 的所有内存单元。内存数组保持原状，因为不存在 mID 为 7 的内存单元。返回 0 。
    return 0;
}