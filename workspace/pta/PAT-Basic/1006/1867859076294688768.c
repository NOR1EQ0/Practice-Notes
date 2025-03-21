#include <stdio.h>
#include <string.h>
int main() {
    char a[4];
    scanf("%s", a);
    int len = strlen(a);
    char* ptr = a;
    for (;len;len--) {
        int num = *ptr - '0';
        switch (len) {
        case 3:
            for (int i = 0; i < num; ++i) {
                putchar('B');
            }
            break;

        case 2:
            for (int i = 0; i < num; ++i) {
                putchar('S');
            }
            break;

        case 1:
            for (int i = 1; i <= num; ++i) {
                putchar('0' + i);
            }
            break;
        default:
            break;
        }
        ptr++;
    }
    putchar('\n');
    return 0;
}