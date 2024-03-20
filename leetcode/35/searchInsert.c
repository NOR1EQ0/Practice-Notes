#include <stdio.h>
#include <stdlib.h>

int searchInsert(int *nums, int numsSize, int target)
{
    int back = numsSize - 1;
    int front = 0;
    int position = 0;
    for (; front<back;)
    {
        if (nums[front] == target)
        {
            position = front;
            break;
        }
        else if (nums[back] == target)
        {
            position = back;
            break;
        }
        front++;
        back--;
    }
    return position;
}

int main()
{
    int nums[4] = {1, 3, 5, 6};
    int numsSize = sizeof(nums) / sizeof(int);
    int target = 5;
    int result = searchInsert(nums, numsSize, target);
    printf("Array: [1, 3, 5, 6]\nTarget: 5\nExpected Output: 2\n");
    printf("Result: %d\n", result);
    return 0;
}