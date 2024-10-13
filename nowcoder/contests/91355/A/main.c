#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// 升序
// int cmp(const void* a, const void* b) {
//     return (*(const int*)a > *(const int*)b) - (*(const int*)a < *(const int*)b);
// }

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        int n, k;
        scanf("%d%d", &n, &k);
        if (k > n) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &k);
            }
            printf("NO\n");
            continue;
        }
        int arr[n];
        int stack[k];
        for (int j = 0; j < n; ++j) {
            scanf("%d", &arr[j]);
        }
        int* tail = stack + k;
        int* ptr = stack;
        int ans = 0;
        for (int* ptr = stack; ptr < tail; ++ptr) { if (*ptr == 0) *ptr = 1; } // 抽奖
        // qsort(arr, n, sizeof(int), cmp);
        for (int* j = arr; j < tail; j++) {
            ans++;
            if (*j == ans) {
                ptr++;
            } else {
                if (*j > k) {
                    continue;
                } else {
                    stack[*j - 1] = 0;
                }
            }
        }
        bool flag = true;
        for (; ptr < tail; ptr++) {
            if (*ptr) {
                flag = false;
                break;
            }
        }
        if (flag) {
            printf("YES\n");
        } else
            printf("NO\n");
        // 5 5
        // 100 123 23 45 6
        // ? ? ? ? ?
    }
    return 0;
}