#include <stdio.h>
#include <stdlib.h>

int searchInsert(int *nums, int numsSize, int target)
{
    int left = 0, right = numsSize - 1, mid;
    if (target > nums[numsSize - 1])
    {
        return numsSize;
    }
    while (left < right)
    {
        mid = (left + right) / 2;
        if (nums[mid] >= target)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}

int main()
{
    int nums[4] = {1, 3, 5, 6};
    int numsSize = sizeof(nums) / sizeof(int);
    int target = 7;
    int result = searchInsert(nums, numsSize, target);
    printf("Array: [1, 3, 5, 6]\nTarget: 5\nExpected Output: 2\n");
    printf("Result: %d\n", result);
    return 0;
}