#include <stdio.h>

int countSegments(char *s)
{
    int ans = 0;
    for (char *i = s; *i; i++)
    {
        if (*i != ' ' && (*(i + 1) == ' ' || !*(i + 1)))
        {
            ans++;
        }
        else
            continue;
    }
    return ans;
}

int main()
{
    char str[] = "a, b, c";
    int segments = countSegments(str);
    printf("%d", segments);
    return 0;
}