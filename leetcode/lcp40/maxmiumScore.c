#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return *(const int*)b - *(const int*)a;
}

int maxmiumScore(int* cards, int cardsSize, int cnt) {
    qsort(cards, cardsSize, sizeof(int), cmp);
    int ans = 0;
    int even = cards[0] % 2 ? 1 : 0;
    for (int i = 0;i < cnt; ++i) {
        if (even) {
            for (int j = 0; j < cardsSize && i <cnt; ++j) {
                if (cards[j] % 2) {
                    ans += cards[j];
                    i++;
                }
            }
        }
    }
    return ans % 2 ? 0 : ans;
}