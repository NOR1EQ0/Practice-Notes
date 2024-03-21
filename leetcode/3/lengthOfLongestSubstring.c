#include <stdio.h>
#include <stdlib.h>

int lengthOfLongestSubstring(char *s)
{
    int left = 0, right = 0, length = 0;
    while (s[right])
    {
        if (left != right)
        {
            if (s[left] == s[right])
            {
                length=right-left-1;
                left = right;
            }
        }
        else
        {
            if (right-left-1>=length)
            {
                length=right-left-1;
            }
            
        }
        
        right++;
    }
    return length;
}

int main()
{
    char s[] = "pwwkew";
    int length = lengthOfLongestSubstring(s);
    printf("String: %s\nExpected Output: 3\nResult: %d", s, length);
    return 0;
}