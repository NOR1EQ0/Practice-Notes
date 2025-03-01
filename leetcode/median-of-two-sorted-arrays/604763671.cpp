#include <bits/stdc++.h>

using namespace std;


// Bad time complexity O(N(logN)) but accepted
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for (auto i : nums2) {
            nums1.insert(lower_bound(nums1.begin(), nums1.end(), i), i);
        }
        auto len = nums1.size();
        if (len % 2) {
            return (double)(nums1.at(len / 2));
        } else {
            return (double)(nums1.at(len / 2 - 1) + nums1.at(len / 2)) / 2.0;
        }
    }
};

int main() {
    Solution loc;
    vector<int> a = {1,2};
    vector<int> b = {3,4};
    double c;
    c = loc.findMedianSortedArrays(a, b);
    cout << c << endl;
    system("pause");
    return 0;
}