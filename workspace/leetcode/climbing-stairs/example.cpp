#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int p = 0, q = 0, r = 1;
        for (int i = 1; i <= n; ++i) {
            p = q;
            q = r;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
            r = p + q;
        }
        return r;
    }
};
// 作者：力扣官方题解
// 链接：https://leetcode.cn/problems/climbing-stairs/solutions/286022/pa-lou-ti-by-leetcode-solution/
// 来源：力扣（LeetCode）

int main() {
    Solution loc;
    vector<pair<int, int>> input = {
        {2, 2}, {3, 3}
    };
    for (auto i: input) {
        int ans = loc.climbStairs(i.first);
        cout << "Input: " << i.first << " | Result: " << ans << " | ";
        if (ans == i.second) {
            cout << " Correct! (Answer: " << i.second << ")\n"; 
        }
    }
    return 0;
}