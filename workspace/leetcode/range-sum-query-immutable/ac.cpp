#pragma GCC diagnostic push
#pragma GCC diagnostic warning "-Wuninitialized"
#pragma GCC diagnostic warning "-Wstrict-overflow"
#include <bits/stdc++.h>

using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) {
        this->suffixSum.reserve(nums.size());
        int sum = 0;
        for (auto& i: nums) {
            sum += i;
            this->suffixSum.emplace_back(sum);
        }
    }

    int sumRange(int left, int right) {
        if (left == 0) {
            return this->suffixSum.at(right);
        }
        return this->suffixSum.at(right) - this->suffixSum.at(left-1);
    }

private:
    vector<int> suffixSum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

int main() {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray* obj = new NumArray(nums);
    cout << obj->sumRange(0,2) << '\n';
    cout << obj->sumRange(2,5) << '\n';
    cout << obj->sumRange(0,5) << '\n';
    return 0;
}
#pragma GCC diagnostic pop