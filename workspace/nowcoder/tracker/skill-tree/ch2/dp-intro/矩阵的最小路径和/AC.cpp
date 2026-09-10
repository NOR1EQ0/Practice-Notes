#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;
ll arr[2005][2005];
ll dp[2005][2005];
static inline void solve() {
    ll n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
            dp[i][j] = arr[i][j];
            if (i > 1 && j > 1) {
                dp[i][j] += min(dp[i - 1][j], dp[i][j - 1]);
            } else {
                if (i <= 1) {
                    dp[i][j] += dp[i][j - 1];
                } else {
                    dp[i][j] += dp[i - 1][j];
                }
            }
        }
    }
    cout << dp[n][m] << '\n';
}
int main() {
#if defined(ONLINE_JUDGE) || 1
    ios::sync_with_stdio(0), cin.tie(0);
#elif 10
    freopen("1.in", "rb", stdin);
#endif
    ll t = 1;
    while (t--) {
        solve();
    }
}