#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct figure {
    bool facing; // 0 in 1 out
    char id[11];
} figure;

int main() {
    int fig, cmds, pos = 0;
    scanf("%d %d", &fig, &cmds);
    figure toys[fig];
    for (int i = 0; i < fig; ++i) {
        scanf("%d %s", &toys[i].facing, toys[i].id);
    }

    // start from 1st
    for (int i = 0; i < cmds; ++i) {
        int a, s;
        /**
         * a: 1 right 0 left
         * s: steps
         */
        scanf("%d %d", &a, &s);
        // for (int j = 0; s > fig; s -= fig);
        s %= fig;
        if (a ^ toys[pos].facing == false) {
            s = -s;
        }
        // a: rotate
        if (pos + s >= fig) {
            pos = s - fig + pos;
        } else if (pos + s < 0) {
            pos = fig - ((int)abs(s) - pos);
        } else {
            pos += s;
        }
    }

    printf("%s", toys[pos].id);
    return 0;
}