#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        auto f = lower_bound(nums.begin(), nums.end(), k);
        return f-nums.begin();
    }
};

int main() {
    vector<int> vec{2,11,10,1,3};
    int k = 10;
    Solution a;
    cout << a.minOperations(vec, k) << endl;
    return 0;
}