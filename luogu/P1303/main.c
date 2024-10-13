#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define ull unsigned long long
#define max (unsigned)1e9
// 64bit 1e18

// 返回大数数组
ull* bigarr(const char* in, int* len) {
    *len = 1;
    int inlen = strlen(in);
    int bit = 0;
    ull* arr = (ull*)malloc(sizeof(ull));
    for (char* ptr = &(in[inlen - 1]); ptr >= in; ptr--) {
        if (bit >= 9) {
            bit = 0;
            *len++;
            arr = (ull*)realloc(arr, sizeof(ull) * *len);
        }
        arr[*len - 1] += (*ptr - '0') * (unsigned)pow(10, bit);
        bit++;
    }
    for (int i = *len - 1; i >= 0; i--) {
        printf("%llu", arr[i]);
    }
    return arr;
}

int main() {
    char in[2002];
    scanf("%s", in);
    int inlen = strlen(in);
    int bit = 0;
    int len = 1;
    ull* arr = (ull*)malloc(sizeof(ull));
    for (char* ptr = &(in[inlen - 1]); ptr >= in; ptr--) {
        if (bit >= 9) {
            bit = 0;
            len++;
            arr = (ull*)realloc(arr, sizeof(ull) * len);
        }
        arr[len - 1] += (*ptr - '0') * (unsigned)pow(10, bit);
        bit++;
    }
    for (int i = len - 1; i >= 0; i--) {
        printf("%llu", arr[i]);
    }
    return 0;
}