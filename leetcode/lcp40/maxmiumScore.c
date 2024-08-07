#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(const int*)a < *(const int*)b) - (*(const int*)a > *(const int*)b);
}

int maximumScore(int* cards, int cardsSize, int cnt) {
    qsort(cards, cardsSize, sizeof(int), cmp);
    int evenSum = 0, oddSum = 0;
    // Start from biggest even number.
    for (int i = 0, j = 0, odd = 0; j < cardsSize && i < cnt; ++j) {
        if (j == cardsSize - 1 && cards[cardsSize] % 2 && !odd) {
            if ((cnt - i) % 2) {
                evenSum = 0;
                break;
            } else {
                odd = 1, j = 0;
            }
        }
        if (!odd) {
            if (cards[j] % 2 == 0) {
                evenSum += cards[j];
                i++;
            }
        } else {
            if (cards[j] % 2) {
                evenSum += cards[j];
                i++;
            }
        }
    }
    // Start from biggest odd number
    for (int i = 0, j = 0, even = 0; j < cardsSize; ++j) {
        if (j == cardsSize - 1 && cards[cardsSize] % 2 == 0 && even == 0) {
            if (i % 2) {
                oddSum = 0;
                break;
            } else {
                even = 1, j = 0;
            }
        }
        if (even) {
            if (cards[j] % 2 == 0) {
                evenSum += cards[j];
                i++;
            }
        } else {
            if (cards[j] % 2) {
                evenSum += cards[j];
                i++;
            }
        }
    }
    return evenSum > oddSum ? evenSum : oddSum;
}