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
    int maxProduct(int n) {
        string s = to_string(n);
        ranges::sort(s, greater());
        return int(s[0] - '0') * (s[1] - '0');
    }
};