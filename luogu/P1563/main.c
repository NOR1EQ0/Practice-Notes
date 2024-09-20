#include <stdio.h>
#include <stdbool.h>

typedef struct figure {
    bool facing; // 0 in 1 out
    char id[11];
} figure;

int main() {
    int fig, cmds;
    scanf("%d %d", &fig, &cmds);
    figure toys[fig];
    for (int i = 0; i < fig; ++i) {
        scanf("%d %s", &toys[i].facing, &toys[i].id);
    }
    for (int i = 0; i < cmds; ++i) {
        int a, s;
        /**
         * a: 1 right 0 left
         * s: steps
         */
        scanf("%d %d", &a, &s);
        
    }
    return 0;
}