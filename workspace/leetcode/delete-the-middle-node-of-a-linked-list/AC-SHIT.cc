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
public:
    ListNode* deleteMiddle(ListNode* head) {
        return head->next ? ([](ListNode* prev, ListNode* next) -> void {
            while ((next = next->next ? next->next->next : nullptr) && (prev = prev->next));
            prev->next = prev->next ? prev->next->next : nullptr;
        }(head, head->next),
                             head)
                          : nullptr;
    }
};