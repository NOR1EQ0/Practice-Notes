#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(const int*)a < *(const int*)b) - (*(const int*)a > *(const int*)b);
}

int main() {
    int n, ans = 0;
    scanf("%d", &n);
    int arr[n];
    int zero[n];
    memset(zero, 0, sizeof(int) * n);
    for (int i = 0; i < n;i++) {
        scanf("%d", &arr[i]);
    }
    while (1) {
        qsort(arr, n, sizeof(int), cmp);
        if (!memcmp(arr + 1, zero + 1, sizeof(int) * (n - 1))) {
            break;
        }
        arr[0]--;
        arr[1]--;
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}