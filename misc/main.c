#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdint.h>
#include <limits.h>
#include <string.h>
#include <stddef.h>
#include <math.h>

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int arr[n];
    memset(arr, 0, sizeof(int) * n);
    for (int i = 0; i < m; ++i) {
        int in;
        scanf("%d", &in);
        in--;
        arr[in] = 1;
    }
    int headptr = 0, tailptr = n - 1;
    int headDistance, tailDistance, tailM = 0, headM = 0;
    bool pig = true, pigStatus = true;
    for (int i = 0; i < n; ++i, pig = !pig) {
        bool direction = true; // true = right, false = left
        int flag = 0;
        for (int i = headptr; flag != 2 && i < n; ++i) {
            if (arr[i]) {
                flag = 1;
            }
            if (flag == 1 && arr[i] == 0) {
                flag = 2;
            }
        }
    }
    if (pigStatus) {
        printf("Xiaozhu Hahaha\n");
    } else {
        printf("Goldye\n");
    }
    return 0;
}