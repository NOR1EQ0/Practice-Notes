#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;
char buffer[1005];
ll arr[1005][1005];
ll presum[1005][1005];
static inline void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> buffer;
        for (int j = 1; j <= m; j++) {
            arr[i][j] = buffer[j - 1] - '0';
            presum[i][j] = arr[i][j] + presum[i - 1][j] + presum[i][j - 1] - presum[i - 1][j - 1];
        }
    }
    ll ans = 0;
    int endn = n - k + 1,
        endm = m - k + 1;
    for (int i = 1; i <= endn; i++) {
        for (int j = 1; j <= endm; j++) {
            auto tmp = presum[i + k - 1][j + k - 1] - presum[i + k - 1][j - 1] - presum[i - 1][j + k - 1] + presum[i - 1][j - 1];
            if (tmp) ans++;
        }
    }
    cout << ans << '\n';
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