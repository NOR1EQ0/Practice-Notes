#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    int n;
    bool flag = true;
    scanf("%d", &n);
    char str[n + 1];
    scanf("%s", str);
    for (char* ptr = str; flag; ptr++, flag = true) {
        if ((*ptr == 'f' && *(ptr + 1) == 'c') || (*ptr == 't' && *(ptr + 1) == 'b')) {
            memmove(ptr, ptr + 2, sizeof(char) * (str + strlen(str) - (ptr + 1)));
            flag = true;
        } else {
            flag = false;
        }
        if (ptr >= str + strlen(str) - 1) {
            if (flag) {
                ptr = str;
                continue;
            } else {
                break;
            }
        }
    }
    printf("%d", strlen(str));
    return 0;
}
