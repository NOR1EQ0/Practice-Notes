// 非赛时完成

#include <stdlib.h>
#include <string.h>

// Submission Begin
int* resultsArray(int* nums, int numsSize, int k, int* returnSize) {
    *returnSize = numsSize - k + 1;
    int* ans = (int*)malloc(sizeof(int) * *returnSize);
    int* ptr = ans;
    if (k == 1) {
        memcpy(ans, nums, sizeof(int) * *returnSize);
        return ans;
    }
    int buf[k];
    for (int i = 0; i < *returnSize; i++) {
        *buf = nums[i];
        for (int j = 1; j < k; j++) {
            buf[j] = buf[j-1] + 1;
        }
        if (memcmp(buf, nums + i, sizeof(int) * k) || buf[k - 1] == buf[0]) {
            *ptr = -1;
        } else {
            *ptr = buf[k - 1];
        }
        ptr++;
    }
    return ans;
}
// Submission End

// Test
int main() {
    int nums[] = { 1,3,4 };
    int k = 2;
    int returnSize;
    int* arr = resultsArray(nums, 3, k, &returnSize);
    return 0;
}