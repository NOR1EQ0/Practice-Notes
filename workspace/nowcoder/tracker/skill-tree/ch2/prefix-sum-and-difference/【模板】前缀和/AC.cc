#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        ll tmp;
        cin >> tmp;
        v[i] = v[max(0, i - 1)] + tmp;
    }
    while (m--) {
        int l, r;
        cin >> l >> r;
        ll sum = v[r - 1];
        if (l > 1) {
            sum -= v[l - 2];
        }
        cout << sum << '\n';
    }
}