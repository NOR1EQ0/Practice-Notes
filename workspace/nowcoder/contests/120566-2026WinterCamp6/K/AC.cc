#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll m, n, z;
    cin >> m >> n >> z;
    ll loopcnt = m + n;
    ll left = z % loopcnt;
    if (!left) cout << '1';
    else if (left <= m) {
        cout << '0';
    } else {
        cout << '1';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}