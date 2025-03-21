#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char a[32], b[32];
    int floata = 0; int floatb = 0;
    bool fa = false, fb = false;
    scanf("%s %s", a, b);
    for (int i = 0; i < 32 && floata < 7 && floatb < 7; ++i, floata += fa, floatb += fb) {
        if (a[i] == '.' && !fa) {
            if (b[i+1] != '.')
            fa = true;
        }
        if (b[i] == '.' && !fb) {
            fb = true;
        }
        if (a[i] != b[i]) { puts("NO"); return 0; }
    }
    puts("YES");
    return 0;
}