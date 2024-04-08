#include <stdio.h>

int maximumCount(int *nums, int numsSize)
{
    int positiveCount = 0, negativeCount = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] > 0)
        {
            positiveCount++;
        }
        else if (nums[i] < 0)
        {
            negativeCount++;
        }
    }
    return positiveCount > negativeCount ? positiveCount : negativeCount;
}

int main(){
    int nums[]={-3,-2,-1,0,0,1,2};
    int numsSize=sizeof(nums)/sizeof(int);
    int result=maximumCount(nums,numsSize);
    printf("Array: [-3,-2,-1,0,0,1,2]\nExpected Output: 3\nResult: %d\n",result);
    return 0;
}