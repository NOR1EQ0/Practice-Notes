#include <stdlib.h>
#include <stdio.h>

int main() {
    int ptr, travel = 0;
    char str[27];
    scanf("%s", str);
    // search A
    for (int i = 0; i < 26; i++) {
        if (str[i] == 'A') { ptr = i; break; }
    }
    for (char end = 'B'; end != 'Z' + 1;) {
        for (int i = 0; i < 26; i++) {
            if (str[i] == end) {
                end++;
                travel = travel + (abs(ptr - i));
                ptr = i;
                break;
            }
        }
    }
    printf("%d\n", travel);
    return 0;
}