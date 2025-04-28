// 自己尝试简单的数组栈实现
#include <stdio.h>
#include <stdlib.h>

/**
 * 构造栈
 */
int* newStack(int size, int* top) {
    *top = -1;
    return (int*)malloc(sizeof(int) * size);
}

/**
 * 入栈
 */
void push(int* stack, int* top, int size, int val) {
    if (*top == size - 1) {
        return puts("Stack is full.");
    }
    (*top)++;
    stack[*top] = val;
}

/**
 * 出栈
 */
void pop(int* stack, int* top) {
    if (*top <= -1) {
        return puts("Stack is empty.");
    }
    (*top)--;
}

/**
 * 访问栈内元素
 */
int access(int* stack, int index, int top) {
    if (index > top || index <= -1) {
        puts("The index given is out of the boundary of the stack.");
        return -1;
    }
    return (stack[index]);
}

/**
 * 访问栈顶元素
 */
int peek(int* stack, int top) {
    return access(stack, top, top);
}

/**
 * 析构栈
 */
void freeStack(int* stack) { free(stack); }

int main() {
    int top;
    int size = 3;
    int* stack = newStack(size, &top);
    return 0;
}
