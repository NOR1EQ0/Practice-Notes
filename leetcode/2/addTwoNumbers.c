#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode, *LinkList;

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *ans = (struct LinkNode *)malloc(sizeof(struct ListNode));
    ans->next = NULL, ans->val = 0;
    struct ListNode *ptr = ans;
    int carry = 0;
    if (!l1->val)
    {
        l1 = l1->next;
    }
    if (!l2->val)
    {
        l2 = l2->next;
    }

    while (l1 || l2)
    {
        if (l1->val + l2->val > 9) {
            carry = 1;
            ans = l1->val + l2->val - 10;
        }
        else {
            carry = 0;
            ans = l1->val + l2->val;
        }
        l1 = l1->next ? l1->next : l1;
        l2 = l2->next ? l2->next : l2;
        ans->next = l1 || l2 ? (struct ListNode *)malloc(sizeof(struct ListNode)) : NULL;
    }

    return ans->next;
}

int main(int argc, char const *argv[])
{
    struct LinkList *l1;
    return 0;
}