#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct queue {
    int* nums;
    int front, size, capacity;
} arrayQueue;

arrayQueue* newArrayQueue(int capacity) {
    arrayQueue* queue = (arrayQueue*)malloc(sizeof(arrayQueue));
    queue->size = 0;
    queue->front = 0;
    queue->size = 0;
    queue->nums = (int*)malloc(sizeof(int) * capacity);
    return queue;
}

/**
 * 析构
 */
void delArrayQueue(arrayQueue* queue) {
    free(queue->nums);
    free(queue);
}

/**
 * 队列长度
 */
int size(arrayQueue* queue) { return queue->size; }

/**
 * 队列容量
 */
int capacity(arrayQueue* queue) { return queue->capacity; }

/**
 * 是否为空队列
 */
bool isEmpty(arrayQueue* queue) {return !queue->size;}

/**
 * 入队
 */
void push(int val) {

}

/**
 * 出队
 */
int pop(arrayQueue* queue) {}