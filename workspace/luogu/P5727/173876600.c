#include <stdlib.h>
#include <stdio.h>

int main() {
    int n, num = 0;
    scanf("%d", &n);
    int buf = n;
    int* arr = (int*)malloc(sizeof(int));
    for (int a;n != 1;) {
        if (n % 2) {
            n = n * 3 + 1;
        } else {
            n /= 2;
        }
        num++;
        arr = (int*)realloc(arr,sizeof(int) * num);
        arr[num-1] = n;
    }
    for (int i = num - 1; i >= 0; --i) {
        printf("%d ", arr[i]);
    }
    printf("%d ", buf);
    return 0;
}