#include <bits/stdc++.h>
#include "../linklist.hpp"

using namespace std;

class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        using ln = ListNode;
        using pln = ListNode*;
        if (!(pHead1 && pHead2)) {
            return pHead1 ? pHead1 : pHead2;
        }
        pln p1prev = nullptr;
        pln p1 = pHead1;
        pln p2 = pHead2;
        if (p2->val <= p1->val) {
            p1prev = p2;
            p2 = p2->next;
            p1prev->next = p1;
            pHead1 = p1 = p1prev;
            p1prev = nullptr;
        }
        while (p2) {
            pln insnode = p2;
            p2 = p2->next;
            while (p1) {
                // a weired condition isnt it?
                // well maybe not :P
                if (p1->val <= insnode->val && (p1->next ? (insnode->val <= p1->next->val) : true)) {
                    pln back = p1->next;
                    p1->next = insnode;
                    insnode->next = back;
                    p1 = insnode;
                    break;
                }
                p1 = p1->next;
            }
        }
        return pHead1;
    }
};

int main() {
    Solution a;
    vector<pair<vector<ListNode>, vector<ListNode>>> inputVec = {
        {{1,2,3} , {3,3,3}},
        {{1,3,5} , {1,3,5}},
        {{1,3,5} , {2,4,6}},
        {{-1,2,4}, {1,3,4}}
    };

    for (auto& i : inputVec) {
        for (int j = 0; j < i.first.size() - 1; ++j) {
            i.first[j].next = &i.first[j + 1];
        }
        for (int j = 0; j < i.second.size() - 1; j++) {
            i.second[j].next = &i.second[j + 1];
        }
    }

    for (auto& i : inputVec) {
        auto f = &i.first.front();
        auto r = &i.second.front();
        cout << "First: " << endl;
        printLinklist(f);
        cout << "Second: " << endl;
        printLinklist(r);
        auto ret = a.Merge(f, r);
        cout << "Merged: " << endl;
        printLinklist(ret);
        cout << "-----------------" << endl;
    }
    a.Merge(0, 0);
    return 0;
}