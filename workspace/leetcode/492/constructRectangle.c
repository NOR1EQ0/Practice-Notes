#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *constructRectangle(int area, int *returnSize)
{
    int minPos = 0;
    
}

int main()
{
    int area = 4;
    int returnSize;
    int *result = constructRectangle(area, &returnSize);
    printf("%d %d", result[0], result[1]);
    return 0;
}