#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char* str[32];
    char* ptr = str;
    scanf("%s",str);
    for (;*ptr;ptr++) {
        if (*ptr == str[0]) {
            strcmp(ptr, str);
        }
    }
    return 0;
}