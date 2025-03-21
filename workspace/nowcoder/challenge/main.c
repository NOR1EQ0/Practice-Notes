/**
 * Problem: 日期排序
 * Status: 已放弃
 */
#include <stdio.h>

int cmp(const void* a, const void* b) {
    return (*(const int*)a < *(const int*)b) - (*(const int*)a > *(const int*)b);
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n][3]; // data grid
    for (int i = 0; i < n; i++) {
        scanf("%d/%d/%d", &(a[i][0]), &(a[i][1]), &(a[i][2]));
    }
    for (int i = 0; i < n; i++) {}
}