#include <stdlib.h>
#include <stdio.h>

int main() {
    int num = 0;
    int* fishes = (int*)malloc(sizeof(int));
    for (int a = 1; ; ) {
        scanf("%d", &a);
        if (a != 0) {
            num++;
            fishes = (int*)realloc(fishes, sizeof(int) * num);
            fishes[num - 1] = a;
        } else {
            break;
        }
    }
    for (int i = num - 1; i >= 0; --i) {
        printf("%d ", fishes[i]);
    }
    return 0;
}