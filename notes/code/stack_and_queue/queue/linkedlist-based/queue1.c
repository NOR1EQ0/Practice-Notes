#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

// 单向链表
typedef struct listNode
{
    listNode* next;
    int val;
}listNode, * LinkList;

typedef struct LinkedListQueue {
    listNode* front, * rear;
    int size;
} LinkedListQueue;

/**
 * 构造
 */
LinkedListQueue* newQueue() {
    LinkedListQueue* queue = (LinkedListQueue*)malloc(sizeof(LinkedListQueue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

void delQueue(LinkedListQueue* queue) {
    while (queue->front) {
        listNode* tmp = queue->front;
        queue->front = queue->front->next;
        free(tmp);
    }
    free(queue);
}

/**
 * 入队
 */
void push(LinkedListQueue* queue, int val) {
    listNode* node = (listNode*)malloc(sizeof(listNode));
    if (queue->front) {
        queue->rear->next = node;
    } else {
        queue->front = node;
    }
    queue->rear = node;
    queue->size++;
}

/**
 * 队列长度
 */
int size(LinkedListQueue* queue) {
    return queue->size;
}

/**
 * 访问队首
 */
int peek(LinkedListQueue* queue) {
    assert(size(queue) && queue->front);
    return queue->front ? queue->front->val : 0;
}

/**
 * 出队，返回出队元素
 */
int pop(LinkedListQueue* queue) {
    int num = peek(queue);
    listNode* tmp = queue->front;
    queue->front = queue->front->next;
    free(tmp);
    queue->size--;
    return num;
}