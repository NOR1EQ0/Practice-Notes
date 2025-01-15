#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int cnt = 0;
        sort(nums.begin(), nums.end());
        int head = 0;
        for (; *(nums.begin() + head) < k && (nums.begin() + head) < nums.end(); cnt++) {
            int x = *(nums.begin() + head), y;
            if (nums.begin() + head + 1 != nums.end()) {
                y = *(nums.begin() + head + 1);
            } else {
                y = x;
            }
            uint64_t ins = (uint64_t)min(x, y) * 2 + (uint64_t)max(x, y);
            int realins = 0;
            if (ins >= numeric_limits<int>().max()) {
                realins = numeric_limits<int>().max();
            } else {
                realins = (int)ins;
            }
            auto ins_it = lower_bound(nums.begin() + head, nums.end(), realins);
            nums.insert(ins_it, realins);
            if (ins_it == nums.begin() + head) {
                head++;
            } else {
                head += 2;
            }
        }
        return cnt;
    }
};

int main() {
    vector<int> nums{ 999999999,999999999,999999999 };
    vector<int> nums2{ 1,1,2,4,9 };
    int k = 1000000000;
    int k2 = 20;
    Solution a;
    cout << a.minOperations(nums, k) << endl;
    cout << a.minOperations(nums2, k2) << endl;
    return 0;
}