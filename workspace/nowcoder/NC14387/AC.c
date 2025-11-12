#include <stdio.h>

int main() {
    int ans = 0;
    char buf[100000];
    scanf("%s", &buf);
    for (char *ptr = buf; *ptr; ptr++) {
        ans += (*ptr - '0');
    }
    printf("%d", ans);
    return 0;
}