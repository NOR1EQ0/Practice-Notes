#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define i64 long long

int cmp(const void* a, const void* b) {
    return (*(const int*)a < *(const int*)b) - (*(const int*)a > *(const int*)b);
}

int main() {
    i64 a[3];
    for (int b = 3; b; b--) {
        scanf("%lld", &a[b - 1]);
    }
    if (a[0] == 0 || a[1] == 0 || a[2] == 0) {
        printf("No\n");
    }
    for (int i = 0; i < 3; ++i) {
        i64 b[3];
        memcpy(b, a, sizeof(i64) * 3);
        b[i] *= 2;
        qsort(b, 3, sizeof(i64), cmp);
        if (b[1] + b[2] > *b) {
            printf("Yes\n");
            return 0;
        } else {
            continue;
        }
    }
    printf("No\n");
    return 0;
}