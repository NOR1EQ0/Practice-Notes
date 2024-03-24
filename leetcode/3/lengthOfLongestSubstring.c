#include <stdio.h>
#include <stdlib.h>

int lengthOfLongestSubstring(char *s)
{
    // This is now still impassable.
    char *left = s, *right = s;
    char length = 0;
    while (*right)
    {
        while (left < right && *left == *right)
        {
            length = right - left++;
        }
        left = left >= right ? left : *right == *(right - 1) ? right++ : left;
        right++;
        length = (*right - *left > length) ? *right - *left : length;
    }
    return (int)length;
    // while (s[right])
    // {
    //     if (right - left >= length)
    //     {
    //         length = right - left;
    //     }
    //     int repeat = 0;
    //     for (int i = left; i < right; i++)
    //     {
    //         if (s[i] == s[right])
    //         {
    //             repeat = 1;
    //             break;
    //         }
    //     }
    //     if (repeat)
    //     {
    //         left++;
    //     }
    //     else if (s[left] == s[right] || s[right] == s[right - 1])
    //     {
    //         left = right++;
    //     }
    //     else
    //     {
    //         right++;
    //     }
    // }
    // if (right - left >= length)
    // {
    //     length = right - left;
    // }
    // return length;
}

int main()
{
    char s[] = "pwwkew";
    int length = lengthOfLongestSubstring(s);
    printf("String: %s\nExpected Output: 3\nResult: %d", s, length);
    return 0;
}