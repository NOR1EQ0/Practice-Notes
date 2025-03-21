#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    getchar();
    int in;
    char hand;
    int pos[2] = { 1,2 };
    int ans = 0;
    for (int i = 0; i < q; i++) {
        scanf("%c %d", &hand, &in);
        getchar();
        int last;
        bool l = hand == 'L' ? true : false;

        if (l) { last = pos[0];pos[0] = in; }
        else { last = pos[1]; pos[1] = in; }

        bool rotate;
        if (in - last > 0) rotate = true; else rotate = false;
        bool change = false;
        if (rotate) {
            if (pos[1 - l] + (in - last) > pos[l]) { rotate = !rotate; change = true; }
        }
        else {
            if (pos[1 - l] + (in - last) < pos[l]) { rotate = !rotate; change = true; }
        }

        if (change) {ans += (n - abs(in - last));}
        else { ans += abs(in - last); }
    }
    printf("%d\n", ans);
    return 0;
}
