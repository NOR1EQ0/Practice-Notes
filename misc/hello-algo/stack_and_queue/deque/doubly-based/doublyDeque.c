#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

// 双向链表部分
/* 双向链表节点 */
typedef struct DoublyListNode {
    int val;                     // 节点值
    struct DoublyListNode* next; // 后继节点
    struct DoublyListNode* prev; // 前驱节点
} DoublyListNode;

/* 构造函数 */
DoublyListNode* newDoublyListNode(int num) {
    DoublyListNode* new = (DoublyListNode*)malloc(sizeof(DoublyListNode));
    new->val = num;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

/* 析构函数 */
void delDoublyListNode(DoublyListNode* node) {
    free(node);
}

// Deque 部分
typedef struct LinkedListDeque {
    DoublyListNode* front, * rear;
    int size;
} LinkedListDeque;

/**
 * 构造
 */
LinkedListDeque* newLinkedListDeque() {
    LinkedListDeque* deque = (LinkedListDeque*)malloc(sizeof(LinkedListDeque));
    deque->front = NULL;
    deque->rear = NULL;
    deque->size = 0;
    return deque;
}

/**
 * 析构
 */
void delLinkedListDeque(LinkedListDeque* deque) {
    for (int i = 0; i < deque->size; ++i) {
        DoublyListNode* tmp = deque->front;
        deque->front = deque->front->next;
        free(tmp);
    }
    free(deque);
}

/**
 * 获得队列长度
 */
int size(LinkedListDeque* deque) { return deque->size; }

/**
 * 判断是否为空队列
 */
bool empty(LinkedListDeque* deque) {
    return (deque->size == 0);
}

/**
 * 入队
 */
void push(LinkedListDeque* deque, int val, bool pushFirst) {
    DoublyListNode* node = newDoublyListNode(val);
    if (empty(deque)) {
        deque->front = deque->rear = node;
    } else if (pushFirst) {
        deque->front->prev = node;
        node->next = deque->front;
        deque->front = node;
    } else {
        deque->rear->next = node;
        node->prev = deque->rear;
        deque->rear = node;
    }
    deque->size++;
}

/**
 * 访问队首元素
 */
int peekFirst(LinkedListDeque* deque) { assert(deque->size && deque->front); return deque->front->val; }

/**
 * 访问队尾元素
 */
int peekLast(LinkedListDeque* deque) { assert(deque->size && deque->rear); return deque->rear->val; }

/**
 * 队首入队
 */
void pushFirst(LinkedListDeque* deque, int val) { push(deque, val, true); }

/**
 * 队尾入队
 */
void pushLast(LinkedListDeque* deque, int val) { push(deque, val, false); }

/**
 * 出队
 */
int pop(LinkedListDeque* deque, bool popFront) {
    if (empty(deque)) {
        return (puts("The deque is empty."), -1);
    }
    int val;
    if (popFront) {
        val = peekFirst(deque);
        DoublyListNode* tmp = deque->front->next;
        if (tmp) {
            tmp->prev = NULL;
            deque->front->next = NULL;
        }
        free(deque->front);
        deque->front = tmp;
    } else {
        val = peekLast(deque);
        DoublyListNode* tmp = deque->front->prev;
        if (tmp) {
            tmp->next = NULL;
            deque->rear->prev = NULL;
        }
        free(deque->rear);
        deque->rear = tmp;
    }
    deque->size--;
    return val;
}

/**
 * 队首出队
 */
int popFirst(LinkedListDeque* deque) { return pop(deque, true); }

/**
 * 队尾出队
 */
int popLast(LinkedListDeque* deque) { return pop(deque, false); }

/**
 * 打印队列
 */
void printDeque(LinkedListDeque* deque) {
    DoublyListNode* ptr = deque->front;
    if (ptr) {
        printf("%d ", ptr->val);
        ptr = ptr->next;
    }
    putchar('\n');
}

// 测试代码
int main() {
    // Initial
    LinkedListDeque* deque = newLinkedListDeque();
    pushLast(deque, 3);
    printDeque(deque);
    pushLast(deque, 2);
    printDeque(deque);
    pushLast(deque, 5);
    printDeque(deque);

    // Progress
    // Step I
    puts("Step I:");
    pushLast(deque, 4);
    printDeque(deque);
    // Step II
    puts("Step II:");
    popLast(deque);
    printDeque(deque);
    // Step III
    puts("Step III:");
    pushFirst(deque, 1);
    printDeque(deque);
    // Step IV
    puts("Step IV:");
    popFirst(deque);
    printDeque(deque);

    puts("Done.");
    return 0;
}