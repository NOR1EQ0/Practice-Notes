#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        int l, r;
        vector<int> lenarr;
        lenarr.reserve(nums.size());

        l = r = 0;
        for (;r < n;r++) {
            while (l <= r) {
                if ([l, r, nums, k]() {
                    int ans = 0;
                    for (int i = l; i < r;i++) {
                        ans |= nums[i];
                        if (ans >= k) return true;
                    }
                    return false;
                    }
                    ()) {
                    l++;
                }
            }
        }
    }
};

int main() {
    vector<int> arr{ 1,2,3 };
    int k = 2;
    Solution a;
    cout << a.minimumSubarrayLength(arr, k) << endl;
    return 0;
}