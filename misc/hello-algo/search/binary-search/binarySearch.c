#include <stdio.h>
#include <stdlib.h>

/**
 * @param nums 输入数组应为升序数组
 */
int binarySearch(int nums[], int len, int target) {
    int i = 0, j = len - 1;
    while (i <= j) {
        int m = i + (i + j) / 2;
        if (nums[m] == target) {
            return m;
        } else if (nums[m] < target) {
            i = m + 1;
        } else {
            j = m - 1;
        }
    }
    return -1; // Fail
}

int main() {
    int nums[] = { 1,3,6,8,12,15,23,26,31,35 };
    printf("9's index: %d\n", binarySearch(nums, 10, 9));
    printf("6's index: %d\n", binarySearch(nums, 10, 6));
    return 0;
}