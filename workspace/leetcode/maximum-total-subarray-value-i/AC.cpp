#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        return (long long)(*ranges::max_element(nums) - *ranges::min_element(nums)) * k;
    }
};