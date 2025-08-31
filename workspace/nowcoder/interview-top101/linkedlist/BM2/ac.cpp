#include <bits/stdc++.h>

using namespace std;

#include "../linklist.hpp"

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        using ln = ListNode;
        ln* ll, * l, * r, * rr;
        if (m == 1) {
            ll = nullptr;
            l = head;
        } else {
            ll = head;
            for (int i = 1; i < m - 1; ++i) {
                ll = ll->next;
            }
            l = ll->next;
        }
        r = l;

        for (int i = m; i < n; ++i) {
            r = r->next;
        }
        rr = r->next;
        /**
         * 4 pointer set above
         * ...-->o-->ll-->l-->o-->o-->r-->rr-->o-->...
         * =>
         * ...-->o-->ll-->l<--o<--o<--r   rr-->o-->...
         * =>
         * ...-->o-->ll-->r-->o-->o-->l   rr-->o-->... (ll->next change)
         */
        {
            auto fore = ll, p = l;
            while (p != rr) {
                auto tmp = p;
                p = p->next;
                tmp->next = fore;
                fore = tmp;
            }
        }

        if (ll) { ll->next = r; } else { head = r; }
        l->next = rr;

        return head;
    }
};

int main() {
    Solution a;
    {
        ListNode in1[] = { 1,2,3,4,5 };
        for (int i = 0; i < 4; ++i) {
            in1[i].next = in1 + i + 1;
        }
        printLinklist(in1);
        auto ret = a.reverseBetween(in1, 1, 4);
        printLinklist(ret);
    }
    return 0;
}