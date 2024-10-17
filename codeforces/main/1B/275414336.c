#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parseRxCy(char* str) {
    int col = 0;
    int base = 26;
    int len = 1;

    char* c = strchr(str, 'C');
    col = atoi(c + 1) - 1;
    while (col >= base) {
        col -= base;
        base *= 26;
        len++;
    }
    int length = c - str + len;
    char ans[length];
    char* letter = ans + len - 1;
    memcpy(letter + 1, str + 1, c - str - 1);
    while (len) {
        *letter = 'A' + col % 26;
        col /= 26;
        len--;
        letter--;
    }
    ans[length - 1] = '\0';
    printf("%s\n", ans);
}

void parseCell(char* str) {
    int col = 0, base = 1, off = 0;
    for (; *str >= 'A'; ++str) {
        col *= 26;
        col += *str - 'A';
        off += base;
        base *= 26;
    }
    col += off;
    printf("R%sC%d\n",str,col);
}

int main() {
    int total;
    scanf("%d", &total);
    for (int i = 0; i < total; ++i) {
        char str[64], buf[64];
        scanf("%s", str);
        int flag = 0;
        for (char* i = str; *i; ++i) {
            if (*i > 'A' && flag) {
                parseRxCy(str);
                flag = 0;
                break;
            } if (*i <= '9') {
                flag = 1;
            }
        }
        if (flag) {
            parseCell(str);
        }
    }
    return 0;
}