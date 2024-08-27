#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const* argv[]) {
    int n, ans = 0;
    scanf("%d", &n);
    int grid[n][3];
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &grid[i][0], &grid[i][1], &grid[i][2]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (abs(grid[i][0] - grid[j][0]) <= 5 &&
                abs(grid[i][1] - grid[j][1]) <= 5 &&
                abs(grid[i][2] - grid[j][2]) <= 5 &&
                abs((grid[i][0] + grid[i][1] + grid[i][2]) -
                    (grid[j][0] + grid[j][1] + grid[j][2])) <= 10
                ) {
                ans++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
