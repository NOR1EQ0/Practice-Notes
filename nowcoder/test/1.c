/**
 * Problem: 兔子的序列
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n, max = 0;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &(a[i]));
    }
    for (int i = 0; i < n; ++i) {
        float buf = sqrt(a[i]);
        if (a[i] / buf != (int)buf) {
            if (a[i] > max) {
                max = a[i];
            }
        }
    }
    printf("%d", max);
    return 0;
}