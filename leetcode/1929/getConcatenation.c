#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *getConcatenation(int *nums, int numsSize, int *returnSize)
{
    *returnSize = 2 * numsSize;
    int *ans = (int *)malloc(sizeof(int) * *returnSize);
    memcpy(ans, nums, sizeof(int) * numsSize);
    memcpy(ans + numsSize, nums, sizeof(int) * numsSize);
    return ans;
}

int main()
{
    int nums[] = {1, 2, 1};
    int returnSize = 0;
    int *ans = getConcatenation(nums, 3, &returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", ans[i]);
    }
    return 0;
}