#include <stdio.h>
#include <stdlib.h>

int dayOfMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int dayOfYear(char *date)
{
    date[4] = '\0';
    date[7] = '\0';
    int ans = 0, year = atoi(date), month = atoi(date + 5) - 1, day = atoi(date + 8);
    for (int *i = dayOfMonth; i < dayOfMonth + month; i++)
    {
        ans += *i;
    }
    ans += day;
    if (month > 1 && (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)))
    {
        ++ans;
    }
    return ans;
}

int main()
{
    printf("%d", dayOfYear("2019-01-09"));
}