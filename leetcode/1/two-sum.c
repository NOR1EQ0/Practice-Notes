/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int *arr = malloc(2 * sizeof(int));
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                arr[0] = i;
                arr[1] = j;
                break;
            }
        }
    }
    *returnSize = 2;
    return arr;
}

int main(int argc, char const *argv[])
{
    int nums[4] = {2, 7, 11, 15};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 9;
    int returnSize;
    int *b = twoSum(nums, numsSize, target, &returnSize);
    return 0;
}
