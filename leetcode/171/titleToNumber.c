#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int titleToNumber(char *columnTitle)
{
    char *ptr = columnTitle + strlen(columnTitle) - 1;
    int ans = 0;
    for (int i = 1; ptr >= columnTitle; i++, ptr--)
    {
        ans += *ptr - 'A' ? (int)pow(*ptr + 1 - 'A', i) : 1;
    }
    return ans;
}

int main()
{
    char column[] = "AB";
    printf("%d", titleToNumber(column));
    return 0;
}