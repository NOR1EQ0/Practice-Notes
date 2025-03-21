#include <stdio.h>
#include <stdbool.h>

int main() {
    int s, v;
    scanf("%d%d", &s, &v);
    int t = 470 - (s + v - 1) / v;
    while (t < 0) {
        t += 24 * 60;
    }
    int min = t % 60;
    int hour = t / 60;
    printf("%02d:%02d\n", hour, min);
    return 0;
}