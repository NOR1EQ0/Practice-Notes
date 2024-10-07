#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 升序
int cmp(const void* a, const void* b) {
    return (*(const int*)a > *(const int*)b) - (*(const int*)a < *(const int*)b);
}

typedef long long i64;
int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        int n;
        scanf("%d", &n);
        i64 arr[n];
        for (int j = 0; j < n; j++) {
            scanf("%lld", &arr[j]);
        }

        qsort(arr, n, sizeof(i64), cmp);
        i64 sum = 0;
        for (int j = 1; j < n; ++j) {
            sum += (i64)floorl(((long double)(arr[j] + arr[j - 1])) / 2.0);
        }
        printf("%lld\n", sum);
    }
    return 0;
}