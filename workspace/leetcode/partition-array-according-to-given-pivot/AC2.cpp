#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;
        ans.resize(nums.size());
        auto len = nums.size();
        int l = 0, r = len - 1;
        for (int i = 0; i < len; i++) {
            if (nums[i] < pivot) {
                ans[l++] = nums[i];
            }
            if (nums[len - i - 1] > pivot) {
                ans[r--] = nums[len - i - 1];
            }
        }
        while (l <= r) {
            ans[l++] = pivot;
        }
        return ans;
    }
};

int main() {
    vector<pair<vector<int>, int>> input = {
        {{9, 12, 5, 10, 14, 3, 10}, 10}, {{-3, 4, 3, 2}, 2}};
    for (auto& [nums, pivot] : input) {
        Solution().pivotArray(nums, pivot);
    }
}