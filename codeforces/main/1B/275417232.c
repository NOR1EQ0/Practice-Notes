#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parseRxCy(char* str) {
    int col = 0;
    int base = 26;
    int len = 1;

    char* c = strchr(str, 'C');
    *c = '\0';
    col = atoi(c + 1) - 1;
    while (col >= base) {
        col -= base;
        base *= 26;
        len++;
    }
    char ans[1 + len];
    ans[len] = '\0';
    char* letter = ans + len - 1;
    while (len) {
        *letter = 'A' + col % 26;
        col /= 26;
        len--;
        letter--;
    }
    printf("%s%s\n", ans, str + 1);
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
    printf("R%sC%d\n", str, col);
}

int main() {
    int total;
    scanf("%d", &total);
    for (int i = 0; i < total; ++i) {
        char str[64], buf[64];
        scanf("%s", str);
        char* c = strrchr(str, 'C');
        if (c == NULL || c == str || *(c - 1) >= 'A') {
            parseCell(str);
        } else {
            parseRxCy(str);
        }
        // int flag = 0;
        // for (char* i = str; *i; ++i) {
        //     if (*i >= 'A' && flag) {
        //         parseRxCy(str);
        //         flag = 0;
        //         break;
        //     } if (*i <= '9') {
        //         flag = 1;
        //     }
        // }
        // if (flag) {
        //     parseCell(str);
        // }
    }
    return 0;
}