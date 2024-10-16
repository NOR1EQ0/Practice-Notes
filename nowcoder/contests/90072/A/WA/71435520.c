#include <stdio.h>
#include <stdlib.h>
#define i64 long long

int cmp(const void* a, const void* b) {
    return (*(const i64*)a < *(const i64*)b) - (*(const i64*)a > *(const i64*)b);
}

int main() {
    i64 n, k;
    i64 ans = 0;
    scanf("%lld%lld",&n,&k);
    i64 arr[n];
    for (i64 i = 0; i < n; ++i) {
        scanf("%lld", &arr[i]);
    }
    qsort(arr, n, sizeof(i64), cmp);
    for (i64 i = 0; i < n - k; ++i) {
        ans += arr[i];
    }
    printf("%lld\n",ans);
    return 0;
}