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
    struct ListNode *ans = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *ptr = ans;
    for (int carry = 0; l1;)
    {
        if (l1->val + l2->val >= 10)
        {
            ans->val = l1->val + l2->val - 10;
        }
        l1 = l1->next, l2 = l2->next;
        ptr->next = l1 ? (struct ListNode *)malloc(sizeof(struct ListNode)) : NULL;
        ptr = ptr->next;
    }
    ptr = NULL;
    free(ptr);
    return ans;
}

int main(int argc, char const *argv[])
{
    return 0;
}