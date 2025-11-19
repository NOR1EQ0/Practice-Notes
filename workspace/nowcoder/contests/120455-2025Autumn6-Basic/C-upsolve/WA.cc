#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr auto MOD = (ll)1e9 + 7;
ll layout[2005][2005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int h, n, m;
    cin >> n >> m >> h;
    for (int i = 0; i < h; i++) {
        ll x, y, z;
        cin >> x >> y >> z;
        x--, y--;

        for (int i = 0; i < m; i++) {
            layout[i][y] = (layout[i][y] % MOD + z % MOD) % MOD;
        }

        for (int i = 0; i < y; i++) {
            layout[x][i] = (layout[x][i] % MOD + z % MOD) % MOD;
        }
        for (int i = y + 1; i < n; i++) {
            layout[x][i] = (layout[x][i] % MOD + z % MOD) % MOD;
        }
    }
    ll cnt{};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            auto thisdamage = (layout[i][j] % MOD) * ((i + 1) % MOD + (j + 1) % MOD);
            cnt = (cnt % MOD + thisdamage % MOD) % MOD;
        }
    }
    cout << cnt << '\n';
}