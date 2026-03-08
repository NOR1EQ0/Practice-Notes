#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        const auto len = capacity.size();
        int minidx = -1;
        int minn = INT_MAX;
        for (size_t i = 0; i < len; i++) {
            if (capacity[i] < itemSize) continue;
            if (capacity[i] < minn) {
                minidx = i;
                minn = capacity[i];
            }
        }

        return minidx;
    }
};