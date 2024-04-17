#include <stdio.h>
#include <math.h>

int scoreOfString(char *s)
{
    char *ptr = s;
    int ans = 0;
    while (*(ptr + 1))
    {
        ans += (int)abs(*ptr - *(ptr + 1));
        ptr++;
    }
    return ans;
}

int main()
{
    int score = scoreOfString("hello");
    printf("%d", score);
    return 0;
}