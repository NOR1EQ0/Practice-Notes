#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

inline struct ListNode* newNode() {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->next = NULL;
    return node;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* linkedList = newNode();
    struct ListNode* ptr = linkedList;
    struct ListNode* last;
    bool carry = false;
    for (;l1 || l2; ) {
        int currentVal = (int)carry;
        if (l1) {
            currentVal += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            currentVal += l2->val;
            l2 = l2->next;
        }
        if (currentVal >= 10) {
            currentVal -= 10;
            carry = true;
        } else
            carry = false;
        ptr->val = currentVal;
        ptr->next = newNode();
        last = ptr;
        ptr = ptr->next;
    }
    if (carry) {
        ptr->val = 1;
    } else {
        last->next = NULL;
    }
    return linkedList;
}

void printList(struct ListNode* list) {
    for (;list;list = list->next) {
        printf("%d ", list->val);
    }
}

int main() {
    struct ListNode* l1 = newNode();
    struct ListNode* p1 = l1;
    p1->val = 2, p1->next = newNode();
    p1 = p1->next;
    p1->val = 4, p1->next = newNode();
    p1 = p1->next;
    p1->val = 3, p1->next = NULL;
    struct ListNode* l2 = newNode();
    struct ListNode* p2 = l2;
    p2->val = 5, p2->next = newNode();
    p2 = p2->next;
    p2->val = 6, p2->next = newNode();
    p2 = p2->next;
    p2->val = 4, p2->next = NULL;
    struct ListNode* list = addTwoNumbers(l1, l2);
    printList(list);
    return 0;
}