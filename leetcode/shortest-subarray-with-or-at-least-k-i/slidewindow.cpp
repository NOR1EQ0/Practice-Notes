#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        
    }
    explicit Solution(int val) {
        this->val = val;
    }
private:
    int val;
};

int main() {
    vector<int> arr{ 1,2,3 };
    int k = 2;
    Solution a = 6;
    cout << a.minimumSubarrayLength(arr, k) << endl;
    return 0;
}