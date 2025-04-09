#include <bits/stdc++.h>

using namespace std;

/**
 * 双指针，移动更矮的边界
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int waterMax = 0;
        int l = 0, r = height.size() - 1;
        while (l < r) {
            int water = min(height[l], height[r]) * abs(r - l);
            waterMax = max(water, waterMax);
            if (height[l] <= height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return waterMax;
    }
};

int main() {
    Solution sol;
    vector<pair<vector<int>, int>> testcases = {
        { {1,8,6,2,5,4,8,3,7}, 49 },
        { {1,1}, 1 }
    };
    for (auto i : testcases) {
        cout << "Input: [";
        for (auto j = i.first.begin(); j != i.first.end() - 1; j++) {
            cout << *j << ", ";
        }
        cout << i.first.back() << "] | Expected: " << i.second << " | Calculation: " << sol.maxArea(i.first) << '\n';
    }
    return 0;
}