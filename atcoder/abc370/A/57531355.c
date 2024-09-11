#include <stdio.h>

int main() {
    int l, r;
    scanf("%d%d", &l, &r);
    if (!(l ^ r)) {
        printf("Invalid\n");
    } else if (l == 1 || r == 0) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}