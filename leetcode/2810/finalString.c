#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

char *finalString(char *s)
{
    char *tmp = (char *)malloc(sizeof(s));
    memset(tmp, NULL, sizeof(s));
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
    char *arr = (char *)malloc(strlen(tmp));
    memcpy(arr,tmp,sizeof(arr));
}

int main(){
    char str1[]="string";
    // char *
    return 0;
}