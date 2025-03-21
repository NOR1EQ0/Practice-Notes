#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    bool laser = false;
    char grid[n][m];
    int Sx, Sy, Ex, Ey;
    for (int i = 0; i < n; i++) {
        scanf("%s", grid[i]);
        char* S = memchr(grid[i], 'S', sizeof(char) * m);
        char* E = memchr(grid[i], 'E', sizeof(char) * m);
        if (S) {
            Sx = (int)S - (int)grid[i];
            Sy = i;
        }
        if (E) {
            Ex = (int)E - (int)grid[i];
            Ey = i;
        }
    }
    while (1) {
        
    }
    return 0;
}