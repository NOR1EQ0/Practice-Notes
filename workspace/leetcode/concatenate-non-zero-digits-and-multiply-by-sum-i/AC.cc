#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
    using ll = long long;
    using ull = unsigned long long;

public:
    long long sumAndMultiply(int n) {
        if (!n) return 0;
        string s = to_string(n);
        s.erase(ranges::remove(s, '0').begin(), s.end());
        ll x = stoll(s);
        ll sum = 0;
        for (auto c : s) {
            sum += (c - '0');
        }
        return x * sum;
    }
};