#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        int l, r, L, R, n;
        scanf("%d %d %d %d", &l, &r, &L, &R);

        if (l - 1)
            l--;
        if (r - 99)
            r++;
        if (L - 1)
            L--;
        if (R - 99)
            R++;

         if (R < l || R - l >(r - l) + (R - L) + 1) {
            printf("0\n");
            continue;
        } else {
            /**
             * if left part on left, n = (+1) - (L) + (r)
             * if right part on left n = (+1) - (l) + (R)
             */
             // if ((r > L && R > l) && )
             // if ((r > L && R > l))
            // int num = (int)fmax(fmax(l, r), fmax(L, R)) - (int)fmin(fmin(l, r), fmin(L, R)) + 1;
            // n = num - abs(L-l) - abs(R-r);
            
        }
        // Print the result
        printf("%d", n);
    }
}