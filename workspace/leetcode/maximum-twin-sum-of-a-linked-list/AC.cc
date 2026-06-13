#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 */
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
    int pairSum(ListNode* head) {
        vector<ll> vec;
        for (ListNode* cur = head; cur; cur = cur->next) {
            vec.push_back(cur->val);
        }
        ll ans = LLONG_MIN;
        ll len = vec.size();
        for (ll i = 0; i < len; i++) {
            ans = max(ans,
                      vec[i] + vec[len - 1 - i]);
        }
        return ans;
    }
};