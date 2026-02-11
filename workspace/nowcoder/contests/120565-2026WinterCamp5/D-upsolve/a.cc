#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1e9 + 7;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    map<ll, ll> m;
    ll total = -1;
    for (int i = 0; i < n; i++) {
        ll c, w;
        cin >> c >> w;
        m[w] = (m[w] + c) % MOD;
        total = (total + c) % MOD;
    }
    if (!total) {
        cout << "0\n";
        return 0;
    }
    ll sum = 0;
    ll presum = 0;
    for (auto it = m.begin(); it != m.end(); it++) {
        auto [w, c] = *it;
        if (it == m.begin()) {
            bool single = c == 1;
            if (single) {
                sum = w;
            } else {
                presum = w;
                for (int i = 1; i < c; i++) {
                    presum = (presum + w) % MOD;
                    sum = (sum + presum) % MOD;
                }
            }
        } else {
            for (int i = 0; i < c; i++) {
                presum = (presum + w) % MOD;
                sum = (sum + presum) % MOD;
            }
        }
    }
    cout << sum << '\n';
}