#include <stdio.h>
#include <stdlib.h>

void rotate(int** grid, int x, int y, int n, int r, int rot) {
    int lt[2] = { x - r, y - r };
    int border = 2 * r + 1;
    int copy[border][border];

    // fill the copy
    for (int i = 0; i < border; ++i) {
        for (int j = 0; j < border; ++j) {
            copy[i][j] = *grid[(lt[1] + j) * border + (lt[0] + i)];
        }
    }

    if (rot) { // reverse

    } else { // normal
        for (int i = 0; i < border; ++i) {
            for (int j = 0; j < border; ++j) {
                *grid[(lt[1] + j) * border + (lt[0] + i)] = copy[i][j];
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    // Create a grid
    int grid[n][n];
    int tmp = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            grid[i][j] = tmp++;
        }
    }

    // Receive cmds
    for (int i = 0; i < m; ++i) {
        int x, y, r, z; // z: rotate 0 normal 1 reverse
        scanf("%d %d %d %d", &x, &y, &r, &z);
        x--; y--; // fix center pos
        rotate(grid, x, y, n, r, z);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", grid[i][j]);
        }
        puts("\n");
    }
    return 0;
}