#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    char in;
    int ptarr[62525]; // col max = 25, row max = 2501
    memset(ptarr, 0, sizeof(int) * 62525);
    bool flag = true; // True W False L
    int pt11[2] = { 0, 0 };
    // grid[2] = { W, L }
    for (int* ptr = ptarr; ptr < ptarr + 62525; ) {
        in = getchar();
        if (in == '\r' || in == '\n') {
            continue;
        }
        if (in == 'E') {
            break;
        }
        if (in == 'W') {
            if (!flag) {
                ptr++;
                flag = true;
            }
        } else if (in == 'L') {
            if (flag) {
                ptr++;
                flag = false;
            }
        }
        *ptr += 1;
    }
    return 0;
}
