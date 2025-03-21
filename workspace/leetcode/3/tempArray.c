#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int lengthOfLongestSubstring(char *s)
{
    int length;
    int *left=s,*right=s;
    int tmp[256];
    memset(tmp,NULL,sizeof(tmp));

}

int main()
{
    char s[] = "pwwkew";
    int length = lengthOfLongestSubstring(s);
    printf("String: %s\nExpected Output: 3\nResult: %d", s, length);
    return 0;
}