#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int main() {
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        char s[101];
        char in;
        scanf("%s", s);
        getchar();
        int len = strlen(s);
        bool cp = true;
        int j;
        int sec = 0;
        for (j = 0; j < len; ++j) {
            in = getchar();
            if (in != s[j]) {
                cp = false;
                if (in != '\n') {
                    sec++;
                }
                break;
            }
        }
        sec += j + (bool)j + (len - j);
        while ((in = getchar()) != '\n') {
            sec++;
        }
        printf("%d\n", sec);
    }
    return 0;
}