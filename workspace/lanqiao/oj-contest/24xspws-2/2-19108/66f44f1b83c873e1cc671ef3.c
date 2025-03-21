#include <stdio.h>
#include <string.h>

int main() {
    char str[101];
    scanf("%s", str);
    if (str[strlen(str) - 1] == '1') {
        str[strlen(str) - 1] = '0';
    } else {
        str[strlen(str) - 1] = '1';
    }
    printf("%s\n", str);
    return 0;
}