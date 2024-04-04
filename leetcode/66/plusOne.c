#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int *plusOne(int *digits, int digitsSize, int *returnSize)
{
    int *tmp = (int *)malloc((digitsSize + 1) * sizeof(int));
    memset(tmp, 0, (digitsSize + 1) * sizeof(int));
    for (int i = 0; i < digitsSize; i++)
    {
        tmp[i + 1] = digits[i];
    }
    for (int i = digitsSize; i > 0; i--)
    {
        if (i == digitsSize)
        {
            if (tmp[i] + 1 >= 10)
            {
                tmp[i] = 0;
                tmp[i - 1]++;
            }
            else
            {
                tmp[i]++;
                break;
            }
        }
        else
        {
        }
        // if (tmp[i] + 1 >= 10)
        // {
        //     tmp[i] = 0;
        //     tmp[i - 1]++;
        // }
        // else if (i == digitsSize)
        // {
        //     tmp[i]++;
        // }
        // else
        // {
        //     continue;
        // }
    }
    *returnSize = tmp[0] == 0 ? digitsSize : digitsSize + 1;
    int *arr = (int *)malloc(*returnSize * sizeof(int));
    memset(arr, 0, *returnSize * sizeof(int));
    if (*returnSize == digitsSize)
    {
        for (int i = 0; i < *returnSize; i++)
        {
            arr[i] = tmp[i + 1];
        }
    }
    else
    {
        for (int i = 0; i < *returnSize; i++)
        {
            memcpy(arr, tmp, *returnSize * sizeof(int));
        }
    }
    free(tmp);
    return arr;
}

int main()
{
    int digits[2] = {9, 9};
    int digitsSize = sizeof(digits) / sizeof(digits[0]);
    int returnSize;
    int *result = plusOne(digits, digitsSize, &returnSize);
    printf("Input Array: [9, 9]\nExpected Output: [1, 0, 0]\nResult: [");
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d", result[i]);
        if (i != returnSize - 1)
        {
            printf(", ");
        }
    }
    printf("]\n");
    return 0;
}