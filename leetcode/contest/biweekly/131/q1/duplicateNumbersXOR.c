#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int duplicateNumbersXOR(int *nums, int numsSize)
{
    int *arr = (int *)malloc(sizeof(int) * (numsSize / 2 + 1));
    memset(arr, 0, sizeof(int) * (numsSize / 2 + 1));
    int *ptr = arr;
    int ans = 0;
    for (int *i = nums; i < nums + numsSize; i++)
    {
        for (int *r = i + 1; r < nums + numsSize; r++)
        {
            if (*r == *i)
            {
                *ptr = *r;
                ptr++;
                break;
            }
        }
    }
    if (!*arr)
    {
        return 0;
    }
    ptr = arr;
    for (; *ptr; ptr++)
    {
        ans ^= *ptr;
    }
    return ans;
}

int main()
{
    int nums[] = {1, 2, 1, 3};
    printf("%d", duplicateNumbersXOR(nums, 4));
    return 0;
}