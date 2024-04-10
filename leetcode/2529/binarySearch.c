#include <stdio.h>

int maximumCount(int *nums, int numsSize)
{
    int left = 0, right = numsSize - 1, mid, positive = 0, negative = 0;
    while (left < right)
    {
        mid = (left + right) / 2;
        if (!nums[mid])
        {
            right = mid;
        }
        else if (nums[mid] < 0)
        {
            if (mid == right)
            {
                return numsSize;
            }
        }
        else
        {
            if (mid==left)
            {
                return numsSize;
            }
            else if (nums[mid-1]==)
            {
                /* code */
            }
            
        }
    }
    return positive > negative ? positive : negative;
}

int main()
{
    int nums[] = {-3, -2, -1, 0, 0, 1, 2};
    int numsSize = sizeof(nums) / sizeof(int);
    int result = maximumCount(nums, numsSize);
    printf("Array: [-3,-2,-1,0,0,1,2]\nExpected Output: 3\nResult: %d\n", result);
    return 0;
}