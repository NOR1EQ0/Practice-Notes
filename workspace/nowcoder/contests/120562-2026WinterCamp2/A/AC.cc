#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        // int a, b, c;
        // cin >> a >> b >> c;

        ll arr[3];
        for (int i = 0; i < 3; i++) cin >> arr[i];

        sort(arr, arr + 3);
        // for (auto i: arr) {
        //     cout << i << ' ';
        // }
        // cout.put('\n');

        if (arr[2] - arr[0] <= 1 && arr[2] - arr[1] <= 1) cout << "YES\n";
        else cout << "NO\n";
    }
}