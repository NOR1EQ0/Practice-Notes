#include <stdio.h>
#include <math.h>

int addDigits(int num)
{
    int bit = 1, tmp = num;
    while (1)
    {
        if (num < 10)
        {
            return num;
        }
        while (tmp > 9)
        {
            tmp /= 10;
            bit++;
        }
        tmp = num % (int)pow(10, bit - 1);
        while (bit - 1)
        {
            tmp = tmp + (num / (int)pow(10, bit - 1) >= 10 ? 0 : num / (int)pow(10, bit - 1));
            bit--;
        }
        num = tmp, bit = 1;
    }
}

int main()
{
    int a = addDigits(128);
    printf("%d", a);
}