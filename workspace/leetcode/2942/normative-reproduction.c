/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int *findWordsContaining(char **words, int wordsSize, char x, int *returnSize)
{
    int *tmp = malloc(wordsSize * sizeof(int));
    int *arr;
    int index = 0;
    for (int i = 0; i < wordsSize; i++)
    {
        for (int j = 0; words[i][j]; j++)
        {
            if (words[i][j] == x)
            {
                tmp[index++] = i;
                break;
            }
        }
    }
    arr = malloc(index * sizeof(int));
    memcpy(arr, tmp, index * sizeof(int));
    free(tmp);
    *returnSize = index;
    return arr;
}

int main()
{
    char *words[4] = {"abc","bcd","aaaa","cbc"};
    int wordsSize = sizeof(words) / sizeof(words[0]);
    char x = 'a';
    int retSize;
    int *b = findWordsContaining(words, wordsSize, x, &retSize);
    free(b);
    return 0;
}