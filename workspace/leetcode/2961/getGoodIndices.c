#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getGoodIndices(int** variables, int variablesSize, int* variablesColSize, int target, int* returnSize) {
    static const int BASE[10][5] = {
        {1,0},
        {1,1},
        {4,2,4,8,6},
        {4,3,9,7,1},
        {2,4,6},
        {1,5},
        {1,6},
        {4,7,9,3,1},
        {4,8,4,2,6},
        {2,9,1}
    };
    int* arr = (int*)malloc(sizeof(int) * variablesSize);
    int* arrptr = arr;
    for (int i = 0; i < variablesSize; ++i) {
        int* v = variables[i];
        int a = v[0] % 10;
        int b = v[1];
        int c = v[2];
        int m = v[3];
        int t = 1;
        b = BASE[a][(b - 1) % BASE[a][0] + 1];
        while (c) {
            if (c % 2) {
                t *= b;
                t %= m;
            }
            b *= b;
            b %= m;
            c >>= 1;
        }
        if (t == target) {
            *arrptr = i;
            arrptr++;
        }
    }
    *returnSize = arrptr - arr;
    return arr;
}

int main() {
    int a[] = { 2,3,3,10 };
    int b[] = { 3,3,3,1 };
    int c[] = { 6,1,1,4 };
    int* d[] = { a,b,c };
    int col = 4;;
    int returnSize;
    int* z = getGoodIndices(d, 3, &col, 2, &returnSize);
    return 0;
}