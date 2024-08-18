#include <stdio.h>
#include <string.h>

int main() {
    char str[8];
    int flag = 0;
    scanf("%s", str);
    int len = strlen(str);
    for (int i = len - 1; i >= 0; i--) {
        if (str[i] == '0') {
            flag++;
            str[i] = '\0';
            continue;
        }
        if (str[i] == '.') {
            if (flag == 3) {
                str[i] = '\0';
            }
            break;
        }
    }
    printf("%s", str);
    return 0;
}