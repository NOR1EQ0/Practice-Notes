#include <stdio.h>
#include <stdlib.h>

/* Submission 554156676 Begin */
void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int removeElement(int* nums, int numsSize, int val) {
    int ans = numsSize;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] == val) {
            ans--;
        }
    }
    int* valptr = nums;
    int* ptr = nums + numsSize - 1;
    for (; valptr < nums + numsSize; ++valptr) {
        if (*valptr == val) {
            for (; ptr < nums + numsSize; --ptr) {
                if (*ptr != *valptr) {
                    swap(valptr, ptr);
                    break;
                }
            }
        }
    }
    return ans;
}
/* Submission 554156676 End */

// Test, no stdout.
int main() {
    int k[] = { 0,1,2,2,3,0,4,2 };
    removeElement(k, 8, 2);
    return 0;
}