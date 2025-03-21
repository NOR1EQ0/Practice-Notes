#include <stdio.h>

int main() {
    char a;
    scanf("%c",&a);
    if (a == 'B') {
        printf("C\n");
    } else if (a == 'E') {
        printf("F\n");
    } else {
        printf("%c#\n", a);
    }
    return 0;
}