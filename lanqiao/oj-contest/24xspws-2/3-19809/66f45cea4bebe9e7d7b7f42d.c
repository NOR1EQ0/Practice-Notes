#include <stdio.h>
#include <ctype.h>

int main() {
    char s[11];
    scanf("%s", s);
    char in;
    getchar();
    while ((in = getchar()) != '\n') {
        if (isdigit(in))
            putchar(s[in - '0']);
            else putchar(in);
    }
    return 0;
}