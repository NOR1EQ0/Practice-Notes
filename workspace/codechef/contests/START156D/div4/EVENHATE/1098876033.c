#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, in, even = 0, odd = 0;
        scanf("%d", &n);
        for (int i = 0;i < n;++i) {
            scanf("%d", &in);
            if (in % 2) odd++;
            else even++;
        }
        if (even&&odd) {
            printf("%d",(odd-1)/2+even+1);
        } else if (even==0) {
            printf("%d",(odd+1)/2);
        } else {
            putchar('0');
        }
        puts("");
    }
    return 0;
}
