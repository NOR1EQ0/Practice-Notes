#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
ll center[2005][2005], row[2005], col[2005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, h;
    cin >> n >> m >> h;
    while (h--) {
        int x, y, z;
        cin >> x >> y >> z;
        x--, y--;
        row[x] = (row[x] % MOD + z % MOD) % MOD;
        col[y] = (col[y] % MOD + z % MOD) % MOD;
        center[x][y] = (center[x][y] % MOD + z % MOD) % MOD;
    }
    ll ans{};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ll damage = (row[i] % MOD + col[j] % MOD - center[i][j] % MOD) % MOD;
            if (damage < 0) damage += MOD;
            ans = (ans % MOD + damage * (i + j + 2)) % MOD;
        }
    }
    cout << ans << '\n';
}