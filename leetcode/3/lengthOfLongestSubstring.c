#include <stdio.h>
#include <stdlib.h>

int lengthOfLongestSubstring(char *s)
{
    int tmp = 0, length = 0, *ptr=0;
}

int main()
{
    char s[] = "pwwkew";
    int length = lengthOfLongestSubstring(s);
    printf("String: %s\nExpected Output: 3\nResult: %d",s,length);
    return 0;
}