#include <stdio.h>
#include <stdlib.h>

int stringToInt(char *src)
{
    int length = 0;
    for (char *ptr, ptr = src; *ptr <= '9' && *ptr >= '0'; length++, ptr++)
        ;
    if (length == 4)
    {
        return (int)(src[0] - '0') * 1000 + (int)(src[1] - '0') * 100 + (int)(src[2] - '0') * 10 + (int)(src[3] - '0');
    }
    if (length == 2)
    {
        return (int)(src[0] - '0') * 10 + (int)(src[1] - '0');
    }
    return 0;
}

int dayOfMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int dayOfYear(char *date)
{
    int ans = 0;
    for (int *i = dayOfMonth; i < dayOfMonth + stringToInt(date + 6); i++)
    {
        ans += *i;
    }
    ans += stringToInt(date + 9);
    return (stringToInt(date) % 4 == 0 && stringToInt(date) % 100 != 0) ? ans + 1 : ans;
}

int main()
{
    printf("%d", dayOfYear("2019-01-09"));
}