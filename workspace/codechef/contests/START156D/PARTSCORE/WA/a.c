#include <stdio.h>
#include <stdlib.h>
#define ull unsigned long long
int cmp(const void* a, const void* b) {
    return (*(const int*)a < *(const int*)b) - (*(const int*)a > *(const int*)b);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        ull n, k;
        scanf("%llu%llu", &n, &k);
        ull arr[n];
        for (int i = 0; i < n; ++i) { scanf("%llu", &arr[i]); }
        qsort(arr, n, sizeof(ull), cmp);
        ull ans = 0;
        ans += arr[0] + arr[n - 1] + arr[k] + arr[k - 1];
        printf("%llu\n", ans);
    }
    return 0;
}
