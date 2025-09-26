#include <bits/stdc++.h>

using namespace std;

// 一个超级搓的写法，竟然ac了，不过也是蹭的分，2054ms过掉的，真是离谱
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        const size_t len = nums.size();
        if (len < 3) {return 0;}
        int op = 0;
        sort(nums.begin(), nums.end());
        for (size_t i = 0; i < len - 2; i++) {
            for (size_t j = i + 1; j < len - 1; j++) {
                for (size_t l = j + 1; l < len; l++) {
                    if (nums[i] + nums[j] > nums[l]){
                        op++;
                    }
                }
            }
        }
        return op;
    }
};

int main() {
    vector<pair<vector<int>, int>> vcases = {
        {{2, 2, 3, 4}, 3},
        {{4, 2, 3, 4}, 4}};
    for (auto& i : vcases) {
        auto [v, n] = i;
        cout << '{';
        for (auto j = v.begin(); j != prev(v.end()); j++) {
            cout << *j << ',';
        }
        cout << v.back() << "} Expected: " << n << " | Calc: " << Solution().triangleNumber(v) << '\n';
    }
    return 0;
}
