#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        const auto len = nums.front().length();
        vector<int> v(len);
        for (int i = 0; i < len; i++) {
            v[i] = stoi(nums[i], nullptr, 2);
        }
        int total = powl(2, len);
        for (int i = 0; i < total; i++) {
            if (find(v.begin(), v.end(), i) == v.end()) {
                string s = bitset<64>(i).to_string().substr(64-len);
                return s;
            }
        }
        string s;
        s.resize(len);
        fill(s.begin(), s.end(), '0');
        return s;
    }
};

int main() {
    vector<vector<string>> v = {
        {"01", "10"},
        {"00", "01"},
        {"111", "011", "001"},
        {"0"}
    };
    for (auto& vs: v) {
        string ans = Solution().findDifferentBinaryString(vs);
        cout << ans << '\n';
    }
}