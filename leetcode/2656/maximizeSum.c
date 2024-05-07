#include <stdio.h>
#include <stdlib.h>

int maximizeSum(int *nums, int numsSize, int k)
{
    int *ptr = nums, max = *nums;
    while (ptr < nums + numsSize)
    {
        max = *ptr > max ? *ptr : max;
        ptr++;
    }
    free(ptr);
    int ans = 0;
    for (int i = 0; i < k; i++)
    {
        ans += max;
        max++;
    }
    return ans;
}