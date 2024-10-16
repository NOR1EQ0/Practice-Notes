#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        int n, k, gold = 0, helped = 0;
        scanf("%d%d", &n, &k);
        for (int j = 0; j < n; ++j) {
            int in;
            scanf("%d", &in);
            if (in == 0) {
                if (gold > 0) {
                    gold--;
                    helped++;
                }
            } else {
                if (in >= k) {
                    gold += in;
                }
            }
        }
        printf("%d\n", helped);
    }
    return 0;
}