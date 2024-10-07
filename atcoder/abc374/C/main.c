#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 降序
int cmp(const void* a, const void* b) {
    return (*(const int*)a < *(const int*)b) - (*(const int*)a > *(const int*)b);
}

typedef long long i64;
int main() {
    int n;
    scanf("%d", &n);
    i64 arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &arr[i]);
    }
    qsort(arr, n, sizeof(i64), cmp);

    int dsum = 0, asum = 0, aptr = n - 1, dptr = 0;

    for (int i = 0; i < n; i++) {
        if (dsum < asum) {
            dsum += arr[dptr];
        }
        asum += arr[aptr];
        dsum += arr[dptr];
    }
    printf("%d", dsum > asum? dsum: asum);
    return 0;
}