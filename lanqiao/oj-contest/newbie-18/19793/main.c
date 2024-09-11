#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        int a, b, c, ans;
        scanf("%d%d%d", &a, &b, &c);
        for (; a < b;) {
            if ((a + 1) % c == 0) {
                a += 2;
            } else if ((a + 2) % c == 0) {
                a++;
            }
            ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}