int distanceTraveled(int mainTank, int additionalTank)
{
    int ans = 0;
    while (additionalTank >= 1)
    {
        if (mainTank < 5)
        {
            ans += mainTank;
            break;
        }
        else
        {
            mainTank-=5;
        }
        
        additionalTank--;
        mainTank++;
        ans += 6;
    }
    return ans;
}