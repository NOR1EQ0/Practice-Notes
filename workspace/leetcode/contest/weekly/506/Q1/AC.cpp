#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
class Solution {
public:
    bool checkGoodInteger(int n) {
        string s = to_string(n);
        ll dsum{}, ssum{};
        for (auto c : s) {
            dsum += (c - '0');
            ssum += (c - '0') * (c - '0');
        }
        return ssum - dsum >= 50;
    }
};