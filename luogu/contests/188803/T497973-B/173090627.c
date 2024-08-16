#include <stdio.h>
#include <stdlib.h>

int main() {
    int wa, ca, ta, wb, cb, tb, a;
    scanf("%d %d %d %d %d %d", &wa, &ca, &ta, &wb, &cb, &tb);
    if (wa > wb) {
        a = 1;
    } else if (wa < wb) {
        a = 0;
    } else {
        if (ca > cb) {
            a = 1;
        } else if (ca < cb) {
            a = 0;
        } else {
            if (ta < tb) {
                a = 1;
            } else {
                a = 0;
            }
        }
    }
    if (a) {
        printf("A\n");
    } else {
        printf("B\n");
    }
    return 0;
}