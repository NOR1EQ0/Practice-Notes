#include <stdio.h>
#include <stdlib.h>

int lengthOfLongestSubstring(char *s)
{
    int left = 0, right = 0, length = 0;
    while (s[right])
    {
        if (right - left >= length)
        {
            length = right - left;
        }
        int repeat = 0;
        for (int i = left; i < right; i++)
        {
            if (s[i] == s[right])
            {
                repeat = 1;
                break;
            }
        }
        if (repeat)
        {
            left++;
        }
        else if (s[left] == s[right] || s[right] == s[right - 1])
        {
            left = right++;
        }
        else
        {
            right++;
        }
    }
    if (right - left >= length)
    {
        length = right - left;
    }
    return length;
}

int main()
{
    char s[] = " ";
    int length = lengthOfLongestSubstring(s);
    printf("String: %s\nExpected Output: 3\nResult: %d", s, length);
    return 0;
}