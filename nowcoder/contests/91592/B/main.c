#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
int diff(int* orig, int len, int head, bool odd) {
    int ret = 0, cnt = 0;
    bool reverse = false;
    int arr[len];
    memcpy(arr, orig + head, sizeof(int) * (len - head + 1));
    memcpy(arr + head, orig, sizeof(int) * head);
    for (int tail = len / 2 + odd, frt = len / 2 - 1; tail < len; ++tail, --frt) {
        if (ret >= 2) {
            break;
        }
        if (arr[tail] != arr[frt]) {
            ret++;
        }
    }
    return ret;
}

int main(int argc, char const* argv[]) {
    int n, k, in, head = 0, cnt = 0;
    scanf("%d%d", &n, &k);
    int arr[k];
    bool odd = k % 2;
    for (int i = 0; i < k; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = k; i < n; i++) {
        scanf("%d", &arr[head++]);
        int flag = diff(arr, k, head, odd);
        if (flag == 1) {
            cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}
