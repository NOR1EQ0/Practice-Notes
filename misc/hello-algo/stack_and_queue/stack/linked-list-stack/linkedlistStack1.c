#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 链表 */

// 单向链表
typedef struct listNode
{
    listNode* next;
    int val;
}listNode, * LinkList;


typedef struct LinkedListStack
{
    listNode* top;
    int size;
} LinkedListStack;

/**
 * 构造
 */
LinkedListStack* newLinkedListStack() {
    LinkedListStack* stack = (LinkedListStack*)malloc(sizeof(LinkedListStack));
    stack->top = NULL;
    stack->size = 0;
}

/**
 * 析构
 */
void delLinkedListStack(LinkedListStack* stack) {
    while (stack->top) {
        listNode* n = stack->top->next;
        free(stack->top);
        stack = n;
    }
}

/**
 * 入栈
 */
void push(LinkedListStack* stack, int val) {
    listNode* node = (listNode*)malloc(sizeof(listNode));
    node->next = stack->top;
    node->val = val;
    stack->top = node;
    stack->size += 1;
}

/**
 * 出栈
 */
void pop(LinkedListStack* stack) {
    listNode* del = stack->top;
    stack->top = stack->top->next;
    stack->size -= 1;
    free(del);
}

/**
 * 获得栈长度
 */
int size(LinkedListStack* stack) { return stack->size; }

int peek(LinkedListStack* stack) {}
