#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

// Give up (temporarily)
char *finalString(char *s)
{
    char *tmp = (char *)malloc(strlen(s) * sizeof(char));
    memset(tmp, 0, sizeof(char) * strlen(s));
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
        else
        {
            *tmpPtr = *ptr;
        }
    }
    char *arr = (char *)malloc((strlen(tmp) + 1) * sizeof(char));
    memcpy(arr, tmp, sizeof(arr));
    return arr;
}

int main()
{
    char str1[] = "string";
    char *result = finalString(str1);
    printf("%s\n", result);
    return 0;
}