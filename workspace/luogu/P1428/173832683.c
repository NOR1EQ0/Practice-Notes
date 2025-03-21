#include <stdio.h>

int main() {
    int t, max;
    scanf("%d", &t);
    int fishes[t];
    for (int i = 0; i < t; ++i) {
        scanf("%d", &fishes[i]);
    }
    printf("0 ");
    if (t == 1)
        return 0;
    for (int i = 1; i < t; ++i) {
        int cute = 0;
        for (int j = 0; j < i; ++j) {
            if (fishes[j] < fishes[i])
                cute++;
        }
        printf("%d ", cute);
    }
    return 0;
}