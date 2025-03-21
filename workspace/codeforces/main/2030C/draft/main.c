#include <stdio.h>
#include <stdbool.h>
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        getchar();
        bool arr[n];
        for (int i = 0;i < n; ++i) arr[i] = getchar() - '0';
        
        getchar();
    }
    return 0;
}
