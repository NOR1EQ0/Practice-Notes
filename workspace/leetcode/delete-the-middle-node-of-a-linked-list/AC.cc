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

    ListNode* walk(ListNode* pos, ptrdiff_t step = 1) {
        while ((pos = pos->next) && --step);
        return pos;
    }

public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head->next) return nullptr;
        ListNode *prev = head, *next = head->next;
        while ((next = walk(next, 2)) && (prev = prev->next));
        prev->next = prev->next->next;
        return head;
    }
};