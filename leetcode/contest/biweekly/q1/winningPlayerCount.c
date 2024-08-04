#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a, const void* b) {
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
 
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

int winningPlayerCount(int n, int** pick, int pickSize, int* pickColSize) {
    int colorNum = 0, ans = 0;
    for (int i = 0; i < pickSize; ++i) {
        if (colorNum < pick[i][1]) {
            colorNum = pick[i][1];
        }
    }
    colorNum++;
    int* score = (int*)malloc(sizeof(int) * n * colorNum);
    memset(score, 0, sizeof(int) * n * colorNum);
    for (int i = 0; i < pickSize; ++i) {
        score[pick[i][0] * colorNum + pick[i][1]]++;
    }
    for (int i = 0; i < n; ++i) {
        qsort(score + n * colorNum, colorNum, sizeof(int),cmp);
    }
    for (int i = 0; i < n; ++i) {
        if (score[i * colorNum] > i) {
            ans++;
        }
    }
    return ans;
}

int main() {

}