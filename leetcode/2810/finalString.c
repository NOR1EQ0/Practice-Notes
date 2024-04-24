#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

// Give up (temporarily)
char *finalString(char *s)
{
    char *tmp = (char *)malloc(sizeof(s));
    memset(tmp, 0, sizeof(s));
    char *tmpPtr = tmp;
    char *ptr = s;
    for (; *ptr; ptr++)
    {
        if (*ptr == 'i')
        {
            for (int i = 1; ptr - i == s; tmpPtr++)
            {
                *tmpPtr = *(ptr - i);
            }
            tmpPtr++;
        }
    }
    char *arr = (char *)malloc((strlen(tmp) + 1) * sizeof(char));
    memcpy(arr, tmp, sizeof(arr));
    return arr;
}

int main()
{
    char str1[] = "string";
    // char *
    return 0;
}