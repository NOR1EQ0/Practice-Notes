#include <stdlib.h>
#include <string.h>

// Submission Begin
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void* a, const void* b) {
    return (*(const int*)a > *(const int*)b) - (*(const int*)a < *(const int*)b);
}
int* resultsArray(int* nums, int numsSize, int k, int* returnSize) {
    *returnSize = numsSize - k + 1;
    
    int* ans = (int*)malloc(sizeof(int) * *returnSize);
    int* ptr = ans;

    // Solution
    int buf[k];
    for (int i = 0; i < numsSize - k + 1; i++) {
        memcpy(buf, nums + i, sizeof(int) * k);
        qsort(buf,k,sizeof(int),cmp);
        
        if (memcmp(buf,nums + i,sizeof(int) * k)) {
            *ptr = -1;
        } else {
            *ptr = buf[k-1];
        }
        ptr++;
    }

    return ans;
}
// Submission End

// Test
int main() {
    int nums[]= {1,2,3,4,3,2,5};
    int k = 3;
    int returnSize;
    int* arr = resultsArray(nums,7,k,&returnSize);
    return 0;
}