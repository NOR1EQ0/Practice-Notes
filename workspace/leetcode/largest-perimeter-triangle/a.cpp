#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end(), less());
        int maxl = nums.front();
        const auto len = nums.size();
        for (size_t i = 1; i < len; i++) {
            
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution s;
    using ll = long long;
    vector<pair<vector<int>, ll>> vcases = {
        {{2,1,2}, 5},
        {{1,2,1,10}, 0}
    };
    for (auto& [c, ans]: vcases) {
        cout << "{";
        for (auto i = c.begin(); i != prev(c.end()); i++) {
            cout << *i << ',';
        }
        cout << c.back() << "} Expected: " << ans << " | Calc: " << s.largestPerimeter(c) << '\n';
    }
    return 0;
}