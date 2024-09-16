#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char const* argv[]) {
    int n, m; /* n = row, m = col*/
    scanf("%d %d", &n, &m);
    char grid[n][m + 1];
    for (int i = 0; i < n; ++i) {
        scanf("%s", grid[i]);
    }
    int arr[n][m];

    // Set bomb
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '*') {
                arr[i][j] = -1;
            } else {
                arr[i][j] = 0;
            }
        }
    }

    // Search
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int* target = &arr[i][j];
            if (grid[i][j] == '*') {
                continue;
            } else {

                // check boundary
                bool flag[4]; // 0123 -> up right down left
                memset(flag, true, sizeof(bool) * 4);
                // left
                if (j == 0)
                    flag[3] = false;
                // up
                if (i == 0)
                    flag[0] = false;
                // right
                if (j == m - 1)
                    flag[1] = false;
                // down
                if (i == n - 1)
                    flag[2] = false;

                // check bomb, from up and check deasil
                // up
                if (flag[0]) {
                    // up
                    if (grid[i - 1][j] == '*') {
                        *target += 1;
                    }
                    // left
                    if (flag[3]) {
                        if (grid[i - 1][j - 1] == '*') {
                            *target += 1;
                        }
                    }
                    // right
                    if (flag[1]) {
                        if (grid[i - 1][j + 1] == '*') {
                            *target += 1;
                        }
                    }
                }
                // down
                if (flag[2]) {
                    // down
                    if (grid[i + 1][j] == '*') {
                        *target += 1;
                    }
                    // left
                    if (flag[3]) {
                        if (grid[i + 1][j - 1] == '*') {
                            *target += 1;
                        }
                    }
                    // right
                    if (flag[1]) {
                        if (grid[i + 1][j + 1] == '*') {
                            *target += 1;
                        }
                    }
                }
                // left
                if (flag[3]) {
                    if (grid[i][j - 1] == '*') {
                        *target += 1;
                    }
                }
                // right
                if (flag[1]) {
                    if (grid[i][j + 1] == '*') {
                        *target += 1;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (arr[i][j] < 0) {
                printf("*");
            } else {
                printf("%d", arr[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}