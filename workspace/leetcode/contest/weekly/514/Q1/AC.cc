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
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        ranges::sort(prices, greater());
        ranges::sort(discounts, greater());
        double ans = 0;
        auto len = prices.size();
        auto mn = min(len, discounts.size()), i = size_t();
        for (; i < mn; i++) {
            ans += (double)prices[i] * (100 - discounts[i]) / 100;
        }
        for (; i < len; i++) {
            ans += (double)prices[i];
        }
        return ans;
    }
};