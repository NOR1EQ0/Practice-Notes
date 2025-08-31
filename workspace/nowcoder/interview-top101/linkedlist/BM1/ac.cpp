#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param head ListNode类
     * @return ListNode类
     */
    ListNode* ReverseList(ListNode* head) {
        if (!head) return head;
        using ln = ListNode;
        ln* tmp = head;
        ln* p = head->next;
        tmp->next = nullptr;
        while (p) {
            ln* fore = tmp;
            tmp = p;
            p = p->next;

            tmp->next = fore;
        }
        return tmp;
    }
};

void printLinklist(ListNode* root) {
    while (root) {
        cout << hex << static_cast<void*>(root) << ": " << dec << root->val << endl;
        root = root->next;
    }
}

int main() {
    Solution a;
    ListNode in1[] = { 1, 2, 3 };
    // in1[0].next = &(in1[1]);
    in1[1].next = &(in1[2]);
    printLinklist(in1);
    auto ret = a.ReverseList(in1);
    printLinklist(ret);
    return 0;
}