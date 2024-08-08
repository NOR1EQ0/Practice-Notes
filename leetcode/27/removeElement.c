#include <stdio.h>
#include <stdlib.h>

void swap(int a, int b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int removeElement(int* nums, int numsSize, int val) {
    int* valptr = nums;
    int* ptr = nums;
    int ans = 0;
    for ( ; ; ++valptr) {
        if (*valptr == val) {
            ptr = valptr;
            for (; ; ++ptr)
            {
                if (*ptr != *valptr) {
                    swap(*ptr, *valptr);
                }
            }
            
        }
    }
}