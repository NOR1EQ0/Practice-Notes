/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *findWordsContaining(char **words, int wordsSize, char x, int *returnSize)
{
    int *arr = malloc(wordsSize * sizeof(int));
    int index = 0;
    for (int i = 0; i < wordsSize; i++)
    {
        for (int j = 0; j < strlen(words[i]); j++)
        {
            if (words[i][j] == x)
            {
                arr[index++] = i;
                break;
            }
        }
    }
    *returnSize = index;
    return arr;
}

int main()
{
    char **words[4][6] = {"abc","bcd","aaaa","cbc"};
    int wordsSize = sizeof(words) / sizeof(words[0]);
    char x = 'a';
    int returnSize[10];
    int *b = findWordsContaining(words, wordsSize, x, returnSize);
    return 0;
}