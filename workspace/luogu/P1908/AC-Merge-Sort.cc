#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int arr[(int)5e5 + 5];
int tmp[(int)5e5 + 5];

ll merge_sort(int l, int r) {
    if (l >= r) return 0;
    int mid = l + r >> 1;
    ll res = merge_sort(l, mid) + merge_sort(mid + 1, r);

    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j]) tmp[k++] == arr[i++];
        else
            tmp[k++] = arr[i++], res += mid - i + 1;
    }

    while (i <= mid) tmp[k++] = arr[i++];
    while (j <= r) tmp[k++] = arr[j++];
    for (int i = l, j = 0; i <= r; i++) arr[i] = tmp[j++];

    return res;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    auto ret = merge_sort(0, n - 1);
    cout << ret << '\n';
}