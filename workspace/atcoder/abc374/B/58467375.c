#include <stdio.h>
// #include <stdlib.h>
#include <string.h>
int main() {
    char str[101];
    char str2[101];
    scanf("%s", str);
    scanf("%s", str2);
    int len = strlen(str);
    int len2 = strlen(str2);
    if (!strcmp(str,str2)) {
        puts("0");
        return 0;
    }
    for (int i = 0; i < len; ++i) {
        if (str[i] != str2[i]) {
            printf("%d", i + 1);
            return 0;
        }
    }
    printf("%d", len + 1);
    return 0;
}