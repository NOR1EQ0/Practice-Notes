#include <stdio.h>
#include <string.h>

/**
 * @param grid 原矩阵
 * @param row 原矩阵行数
 * @param col 原矩阵列数
 */
void transpose(int* grid, int* row, int* col) {
    int n = *row * *col; // count
    int arr[n];
    memcpy(arr, grid, sizeof(int) * n);
    for (int i = 0; i < n; ++i) {
        // for (int j = 0; j < *col; ++j) {
        //     grid[j * *col + i] = arr[i * *row + j];
        // }
        
    }
    // swap
    *row = *row ^ *col;
    *col = *row ^ *col;
    *row = *row ^ *col;
}

int main() {
    int m, n, t;
    // n = row, m = col, t = number of op
    scanf("%d%d%d", &n, &m, &t);
    int cnt = m * n;
    int arr[cnt];

    // Read
    for (int i = 0; i < cnt; ++i) {
        scanf("%d", &arr[i]);
    }

    for (int j = 0; j < t; ++j) {
        int op, a, b;
        scanf("%d", &op);
        switch (op) {
        case 1:
            scanf("%d%d", &n, &m);
            break;
        case 2:
            scanf("%d%d", &a, &a);
            transpose(arr, &n, &m);
            break;
        case 3:
            scanf("%d%d", &a, &b);
            printf("%d\n", arr[a * m + b]);
            break;
        default:
            break;
        }
    }
}