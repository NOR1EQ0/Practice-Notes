#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        auto f = lower_bound(nums.begin(), nums.end(), k);
        if (f==nums.end()) {
            return 0;
        }
        return f-nums.begin()+1;
    }
};

int main() {
    vector<int> vec{1,1,2,4,9};
    int k = 1;
    Solution a;
    cout << a.minOperations(vec, k) << endl;
    return 0;
}