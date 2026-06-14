#include <bits/stdc++.h>
using namespace std;

class Solution {
    using ll = long long;
    using ull = unsigned long long;

public:
    int getLength(vector<int>& nums) {
        ll mx = 1;
        auto len = nums.size();
        for (int l = 0; l < len; l++) {
            unordered_map<int, int> freq;
            unordered_map<int, int> freqcnt;

            for (int r = l; r < len; r++) {
                int x = nums[r];
                int old = freq[x];
                freq[x]++;
                if (old > 0) {
                    if (--freqcnt[old] == 0) freqcnt.erase(old);
                }
                freqcnt[old + 1]++;
                if (freq.size() == 1) {
                    mx = max(mx, (ll)r - l + 1);
                } else if (freqcnt.size() == 2) {
                    auto it = freqcnt.begin();
                    int f1 = it->first, f2 = next(it)->first;
                    if (f1 > f2) swap(f1, f2);
                    if (f2 == 2 * f1) mx = max(mx, (ll)r - l + 1);
                }
            }
        }
        return mx;
    }
};

int main() {
    vector<vector<int>> input = {
        {1, 2, 2, 1, 2, 3, 3, 3}, // 5
        {5, 5, 5, 5},             // 4
        {1, 2, 3, 4}              // 1
    };
    int cnt = 0;
    for (auto& v : input) {
        cout << cnt++ << ' ' << Solution().getLength(v) << endl;
    }
}