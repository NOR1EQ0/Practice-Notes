#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *occurrencesOfElement(int *nums, int numsSize, int *queries, int queriesSize, int x, int *returnSize)
{
    int *answer = (int *)malloc(sizeof(int) * queriesSize);
    int *ptr = answer;
    for (int *i = queries; i < queries + queriesSize; i++)
    {
        int *ptr = -1;
        for (int *j = nums, *target = nums + *i - 1; j < nums + numsSize; j++)
        {
            if (j == target)
            {
                continue;
            }
            if (*j == *target)
            {
                *ptr++;
            }
        }
        *ptr = *ptr + 1 ? *ptr + 1 : -1;
        ptr++;
    }
    *returnSize = queriesSize;
    return answer;
}