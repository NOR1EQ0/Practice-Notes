#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;
        ans.reserve(nums.size());
        auto pivotcnt = ranges::count(nums, pivot);
        for (auto i : nums) {
            if (i < pivot)
                ans.push_back(i);
        }
        for (int i = 0; i < pivotcnt; i++) {
            ans.push_back(pivot);
        }
        for (auto i : nums) {
            if (i > pivot)
                ans.push_back(i);
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