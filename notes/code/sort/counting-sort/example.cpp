#include <bits/stdc++.h>

using namespace std;

int tmp[(size_t)1e9 + 1];
int out[(size_t)1e5];

int* counting_sort(int* arr, int len, int maxn) {
    memset(tmp, 0, sizeof(int) * maxn);
    for (int i = 0; i < len; ++i) tmp[arr[i]]++;
    for (int i = 1; i < maxn; ++i) tmp[i] = tmp[i] + tmp[i - 1]; // Calculate prefix sum
    for (int i = maxn; i > 0; --i) out[tmp[arr[i]]];
    return out;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int in[(size_t)1e5];
    int n;cin >> n;
    int maxn = 0;
    for (int i = 0; i < n; ++i) {
        cin >> in[i];
        maxn = max(maxn, in[i]);
    }
    counting_sort(in, n, maxn);
    return 0;
}