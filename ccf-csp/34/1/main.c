#include <stdio.h>

int main() {
    int p, q;
    scanf("%d%d%d%d", &p, &q, &p, &q);
    int n = p * q;
    int grid[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &grid[i]);
    }
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; ++j) {
            printf("%d ", grid[i * q + j]);
        }
        printf("\n");
    }
}