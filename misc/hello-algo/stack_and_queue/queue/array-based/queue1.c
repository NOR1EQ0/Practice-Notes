#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct queue {
    int* nums;      // 队列数据
    int size,       // 队首索引
        front,      // 队列长度
        capacity;   // 队列容量
} arrayQueue;

/**
 * 构造
 */
arrayQueue* newArrayQueue(int capacity) {
    arrayQueue* queue = (arrayQueue*)malloc(sizeof(arrayQueue));
    queue->size = 0;
    queue->front = 0;
    queue->capacity = capacity;
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
bool isEmpty(arrayQueue* queue) { return !queue->size; }

/**
 * 队首元素
 */
int peek(arrayQueue* queue) {
    assert(queue->size);
    return queue->nums[queue->front];
}

/**
 * 入队
 */
void push(arrayQueue* queue, int val) {
    if (queue->size == queue->capacity) {
        return puts("Queue is full.");
    }
    int rear = (queue->front + queue->size) % queue->capacity;
    queue->nums[rear] = val;
    queue->size++;
}

/**
 * 出队
 */
int pop(arrayQueue* queue) {
    int num =
        queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
}