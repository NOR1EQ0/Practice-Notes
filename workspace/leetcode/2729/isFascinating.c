#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isFascinating(int n) {
    char str[12] = "";
    int a[9];
    memset(a, 0, sizeof(int) * 9);
    sprintf(str, "%d%d%d", n, 2 * n, 3 * n);
    for (char* ptr = str; *ptr; ++ptr) {
        if (*ptr == '0') {
            return false;
        }
        a[*ptr - '1']++;
    }
    for (int i = 0; i < 9; ++i) {
        if (a[i] == 0 || a[i] != 1)
        {
            return false;
        }
    }
    return true;
}

int main() {
    isFascinating(783);
    return 0;
}