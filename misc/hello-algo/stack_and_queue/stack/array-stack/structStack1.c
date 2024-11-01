#include <stdio.h>
#include <stdlib.h>

/**
 * 数组实现的栈结构体
 */
typedef struct arrayStack {
    int* data;
    int size;
    int top;
} arrayStack;

/**
 * 构造数组栈
 */
arrayStack* newArrayStack(int size) {
    arrayStack* stack = (arrayStack*)malloc(sizeof(arrayStack));
    stack->data = (int*)malloc(sizeof(int) * size);
    stack->top = -1;
    return stack;
}

/**
 * 析构数组栈
 */
void deleteArrayStack(arrayStack* stack) { free(stack); }

/**
 * 入栈
 */
void push(arrayStack* stack, int val) {
    if (stack->top >= stack->size - 1) {
        return puts("Stack is full.");
    }
    stack->top++;
    stack->data[stack->top]=val;
}

/**
 * 出栈
 */
void pop(arrayStack* stack) {
    if (stack->top <= -1) {
        return puts("The stack is empty.");
    }
    stack->top--;
}

/**
 * 访问栈内元素
 */
int access(arrayStack* stack, int index) {
    if (stack->top<=-1) {
        puts("The stack is empty.");
        return -1;
    }
    else if (index > stack->top) {
        puts("The index given is greater than the top of the stack.");
        return -1;
    } else if (index <= -1 || index >= stack->size) {
        puts("The index given is out of the boundary of the stack.");
        return -1;
    }
    return stack->data[index];
}

/**
 * 访问栈顶
 */
int peek(arrayStack* stack) {
    return access(stack, stack->top);
}

int main() {
    arrayStack* stack = newArrayStack(5);
    return 0;
}