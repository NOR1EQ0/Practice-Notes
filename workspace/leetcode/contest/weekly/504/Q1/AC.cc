#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int digitFrequencyScore(int n) {
        string s = to_string(n);
        int ans = 0;
        for (auto c: s) {
            ans += (c - '0');
        }
        return ans;
    }
};