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

void sort(int* nums, int len) {
    int base;
    for (int i = 0; i < len; ++i) {
        for (int j = i; j < len; ++j) {
            base = nums[j];
            int index = 0;
            for (int k = 0; k < j; ++k) {
                if (base > nums[k] && base < nums[k + 1]) {
                    index = k + 1; break;
                }
            }
            
        }
    }
}