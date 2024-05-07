#include <stdio.h>

int numberOfEmployeesWhoMetTarget(int *hours, int hoursSize, int target)
{
    int *l = hours, ans = 0;
    while (l < hours + hoursSize)
    {
        ans = *l >= target ? ans + 1 : ans;
        l++;
    }
    return ans;
}

int main()
{
    int hours[5] = {4, 8, 6, 7, 9};
    printf("%d\n", numberOfEmployeesWhoMetTarget(hours, 5, 6));
    return 0;
}