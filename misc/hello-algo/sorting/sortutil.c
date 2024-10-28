#include <stdio.h>
#include <stdbool.h>

void print_array(int* arr, int len, bool endl) {
    for (int i = 0; i < len; ++i) {
        printf("%d ", arr[i]);
    }
    if (endl) printf("\n");
}

void swap(int* a, int* b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}