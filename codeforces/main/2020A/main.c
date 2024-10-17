#include <stdio.h>
#include <stdlib.h>
#include <string.h>

i64* times(i64 n, i64 k, int* returnSize) {
    i64* arr = (i64*)malloc(sizeof(i64));
    int len = 1;
    i64 tmp = 1;
    while (n - tmp >= 0) {
        tmp *= k;
        arr[len - 1] = tmp;
        len++;
        arr = (i64*)realloc(arr, sizeof(i64) * len);
    }
    *returnSize = len - 1;
    return arr;
}

typedef long long i64;
int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        i64 n, k, ans = 0;
        scanf("%lld%lld", &n, &k);
        if ((n % 2) ^ (k % 2)) {
            ans++;
            n--;
        }

    }
    return 0;
}