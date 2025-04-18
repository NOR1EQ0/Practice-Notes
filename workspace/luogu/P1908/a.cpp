#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
int seq[(int)5e5];
int tmp[(int)5e5];

ll merge_sort(int l, int r) {
    if(l >= r) return 0;
    int mid = l + r >> 1;
    ll res = merge_sort(l, mid) + merge_sort(mid + 1, r);

    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        if (seq[i] <= seq[j]) tmp[k++] = seq[i++];
        else {
            tmp[k++] = seq[j++];
            res += mid - i + 1;
        }
    }

    while (i <= mid) tmp[k++] = seq[i++];
    while (j <= r) tmp[k++] = seq[j++];
    for (int i = l, j = 0; i <= r; i++) seq[i] = tmp[j++];
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> seq[i];
    }
    ll ret = merge_sort(0, n - 1);
    cout << ret;
    return 0;
}