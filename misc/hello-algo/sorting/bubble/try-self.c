#include <stdio.h>
#include <stdbool.h>
#define optimize

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
    for (int i = 0; i < len; ++i) {
        #ifdef optimize
        bool flag = false;
        #endif
        for (int j = 0; j < len - 1 - i; ++j) {
            if (nums[j] > nums[j + 1]) {
                swap(nums + j, nums + j + 1);
                #ifdef optimize
                flag = true;
                #endif
            }
        }
        #ifdef optimize
        if (!flag) break;
        #endif
    }
}

int main() {
    int nums[] = { 4,1,3,1,5,2 };
    print_array(nums, 6, true);
    sort(nums, 6);
    print_array(nums, 6, true);
    return 0;
}