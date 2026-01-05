#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reversePrefix(string s, int k) {
        reverse(s.begin(), s.begin() + k);
        return s;
    }
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    vector<tuple<string, int, string>> v = {
        {"abcd", 2, "bacd"}, {"xyz", 3, "zyx"}, {"hey", 1, "hey"}
    };
    for (auto& tp: v) {
        cout << get<0>(tp) << ' ' << get<1>(tp) << ' ' << get<2>(tp) << " -> " << Solution().reversePrefix(get<0>(tp), get<1>(tp)) << '\n';
    }
}