#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/**
 * 双向链表 (Doubly Linked List)
 */

 /* 双向链表结构体 */
typedef struct ListNode
{
    int val;
    struct ListNode* prev;
    struct ListNode* next;
}ListNode, * LinkedList;

/* 创建链表 */
LinkedList newLinkedList(int val) {
    LinkedList list = (LinkedList)malloc(sizeof(LinkedList));
    list->val = val;
    list->prev = NULL; // Previous
    list->next = NULL;
    return list;
}

ListNode* newListNode(int val) { return newLinkedList(val); }

/* 打印链表 */
void printLinkedList(LinkedList list, bool reverse) {
    int cnt = 0;
    if (reverse) {
        puts("Print reversely.\n");
    }
    puts("Address\tValue");
    if (!reverse) {
        while (list) {
            printf("%p\t%d\n", list, list->val);
            ++cnt;
            list = list->next;
        }
    }
    else {
        while (list->next) {
            list = list->next;
        }
        while (list) {
            printf("%p\t%d\n", list, list->val);
            list = list->prev;
            cnt++;
        }
    }
    printf("The number of nodes: %d\n", cnt);
}

/* 删除节点 */
void deleteListNode(ListNode* node) {
    if (node->prev)
        node->prev->next = node->next;
    if (node->next)
        node->next->prev = node->prev;
    free(node);
}

int main(int argc, char const* argv[]) {
    LinkedList list = newLinkedList(5);
    ListNode* node1 = newListNode(7);

    list->next = node1;
    node1->prev = list;
    printLinkedList(list, false);
    printLinkedList(list, true);
    return 0;
}

