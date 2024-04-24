#include <stdio.h>
#include <memory.h>

void moveZeroes(int* nums, int numsSize) {
    int nonZero = 0, *l = nums, *ptr = nums;
    while (ptr < nums + numsSize) {
        if (*ptr != 0) {
            *l = *ptr;
            l++,nonZero++;
        }
        ptr++;
    }
    memset(nums+nonZero,0,sizeof(int)*(numsSize-nonZero));
}

int main() {
    int nums[] = {0,1,0,3,12};
    moveZeroes(nums, 5);
    for (int i = 0; i < 5; i++) {
        printf("%d ", nums[i]);
    }
    return 0;
}