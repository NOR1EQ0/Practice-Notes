#include <stdio.h>
#include <stdlib.h>

int main() {
    int a;
    scanf("%d", &a);
    for (int i = 0; i < a; ++i) {
        int buf1, buf2;
        scanf("%1d%1d", &buf1, &buf2);
        printf("%d\n", buf1 + buf2);
    }
    return 0;
}