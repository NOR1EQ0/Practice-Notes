#include <stdio.h>

int main() {
    int len, q;
    scanf("%d%d", &len, &q);
    char str[len + 1];
    scanf("%s", str);
    for (int i = 0; i < q; ++i) {
        int x;
        char c;
        scanf("%d %c", &x, &c);
        x--;
        str[x] = c;
        x = 0;
        for (char* ptr = str; *ptr || ptr < str + len + 1; ) {
            if (*ptr == 'A' && *(ptr + 1) == 'B' && *(ptr + 2) == 'C') {
                x++;
                ptr += 3;
            } else {
                ++ptr;
            }
        }
        printf("%d\n", x);
    }
    return 0;
}