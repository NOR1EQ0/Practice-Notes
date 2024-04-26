#include <stdio.h>

int distanceTraveled(int mainTank, int additionalTank)
{
    int ans = 0;
    while (additionalTank >= 1)
    {
        if (mainTank < 5)
        {
            ans += mainTank*10;
            break;
        }
        else
        {
            mainTank -= 5;
        }
        additionalTank--;
        mainTank++;
        ans += 50;
    }
    return ans;
}

int main()
{
    int mainTank = 5;
    int additionalTank = 10;
    int ans = distanceTraveled(mainTank, additionalTank);
    printf("%d", ans);
    return 0;
}