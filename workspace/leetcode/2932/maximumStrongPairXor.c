#include <math.h>
#include <stdio.h>

int maximumStrongPairXor(int *nums, int numsSize)
{
    int *l = nums, *r = nums, max = 0;
    while (l < nums + numsSize)
    {
        if (abs(*l - *r) <= (*l < *r ? *l : *r))
        {
            max = max < *l ^ *r ? *l ^ *r : max;
        }
        r = r < nums + numsSize ? r + 1 : l++;

    }
    return max;
}

int main()
{
    int nums[5] = {3, 10, 5, 25, 2};
    int numsSize = 5;
    printf("%d", maximumStrongPairXor(nums, numsSize));
}