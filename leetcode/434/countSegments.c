#include <stdio.h>

int countSegments(char *s)
{
    int ans = 0;
    for (char *i = s; *i; i++)
    {
        if (*i != ' ' && (*(i + 1) == ' ' ^ !*(i + 1)))
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
    char str[] = "Hello, my name is John";
    int segments = countSegments(str);
    printf("String: %s\nExpected Output: 5\nResult: %d\n",str,segments);
    return 0;
}