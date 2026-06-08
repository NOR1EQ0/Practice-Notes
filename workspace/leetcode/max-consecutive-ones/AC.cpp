#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        auto n = nums.size();
        auto cnt = nums[0];
        auto mx = cnt;
        for (int i = 1; i < n; i++) {
            if (nums[i]) {
                cnt++;
            } else {
                mx = max(mx, cnt);
                cnt = 0;
            }
        }
        mx = max(mx, cnt);
        return mx;
    }
};

int main() {
    vector<vector<int>> input = {
        {1, 1, 0, 1, 1, 1}, {1, 0, 1, 1, 0, 1}};
    for (auto& v : input) {
        Solution().findMaxConsecutiveOnes(v);
    }
}