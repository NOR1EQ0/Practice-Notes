#include <stdio.h>

int main(int argc, char const* argv[]) {
    int N, tmp = 1;
    scanf("%d", &N);
    int cnt = N*(N+1)/2;
    int arr[cnt];
    for (int i = 0; i < cnt; ++i) {
        scanf("%d", &arr[i]);
    }
    
    for (int j = 1; j < N + 1; ++j) {
        if (j > tmp) {
            tmp = arr[tmp - 1 + j - 1];
        } else {
            tmp = arr[j - 1]
        }
    }
    printf("%d", tmp);
    return 0;
}
