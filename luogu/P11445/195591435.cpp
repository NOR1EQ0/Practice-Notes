#include <bits/stdc++.h>
using namespace std;
int arr[100];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(arr, 0, sizeof(int) * 100);
    int ans = 0, n;
    cin >> n;
    for (int i = 0; i < 3; ++i) {
        int x;
        cin >> x;
        while (x--) {
            int in;
            cin >> in;
            arr[in-1]++;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (arr[i] != 1) {
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}