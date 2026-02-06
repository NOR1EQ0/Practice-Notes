#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        if (n == 1) {
            cin >> n;
            cout << n << '\n';
            continue;
        }
        if (n == 2) {
            ll tmp;
            cin >> tmp >> n;
            cout << tmp + n << '\n';
            continue;
        }
        ll arr[3];
        arr[1] = LLONG_MIN;
        cin >> arr[0];
        for (int i = 1; i < n - 1; i++) {
            ll tmp;
            cin >> tmp;
            arr[1] = max(arr[1], tmp);
        }
        cin >> arr[2];
        auto maxp = max_element(arr, arr + 3);
        ll ans = *maxp * (n - 2) + arr[0] + arr[2];
        cout << ans << '\n';
    }
}