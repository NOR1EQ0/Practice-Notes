#include <stdio.h>
#include <stdlib.h>

/* 链表结构体 */
typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

/* 构造函数 */
ListNode* newListNode(int val) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

/* 打印链表 */
void printLinkedList(ListNode* listNode) {
    printf("Address Value\n");
    int num = 0;
    while (listNode) {
        printf("%p\t%d\n", listNode, listNode->val);
        listNode = listNode->next;
        num++;
    }
    printf("Linked List Node Number: %d\n", num);
}

/* 插入节点，自行实现 */
void insertListNode(ListNode* prev, ListNode* node) {
    node->next = prev->next;
    prev->next = node;
    puts("Insertion Done.");
}

/* 删除节点 */
void deleteListNode(ListNode* prev) {
    if (!prev->next) return;
    ListNode* ptr = prev->next;
    prev->next = prev->next->next;
    printf("Before val: %d\n", ptr->val);
    free(ptr);
    printf("After val: %d\n", ptr->val);
    puts("Deleted.");
}

/* 访问节点，指定索引 */
ListNode* accessListNodeByIndex(ListNode* list, int index) {
    for (int i = 0; i < index; ++i) {
        if (list = NULL) return;
        list = list->next;
    }
    return list;
}

int main(int argc, char const* argv[]) {
    /* 初始化链表 1 -> 3 -> 2 -> 5 -> 4 */
    // 初始化各个节点
    ListNode* n0 = newListNode(1);
    ListNode* n1 = newListNode(3);
    ListNode* n2 = newListNode(2);
    ListNode* n3 = newListNode(5);
    ListNode* n4 = newListNode(4);
    ListNode* insert = newListNode(8);
    // 构建节点之间的引用
    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    printLinkedList(n0);
    insertListNode(n3, insert);
    printLinkedList(n0);
    deleteListNode(n1);
    printLinkedList(n0);
    return 0;
}
