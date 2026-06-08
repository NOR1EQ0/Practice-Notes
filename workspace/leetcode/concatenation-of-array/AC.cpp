#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        auto n = nums.size();
        nums.resize(2 * n);
        copy(nums.begin(), nums.begin() + n, nums.begin() + n);
        return nums;
    }
};