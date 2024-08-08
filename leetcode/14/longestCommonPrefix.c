#include <stdio.h><
#include <stdlib.h>
#include <stdbool.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    int i = 0;
    bool flag = false;
    for (; ; ++i) {
        if (!strs[0][i]) {
            break;
        }
        for (int j = 1; j < strsSize; ++j) {
            if (strs[j][i] != strs[0][i]) {
                flag = true;
                break;
            }
        }
        if (flag)
            break;
    }
    strs[0][i] = '\0';
    return strs[0];
}