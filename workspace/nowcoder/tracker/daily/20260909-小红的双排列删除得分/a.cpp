#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;
static inline void solve() {
    ll n;
    cin >> n;
    vector<ll> v(2 * n + 1);
    vector<ll> presum(2 * n + 1);
    vector<ll> idxl(n + 1, -1);
    vector<ll> idxr(n + 1, -1);
    vector<ll> dp(2 * n + 1);

    for (ll i = 1; i <= 2 * n; i++) {
        cin >> v[i];
        presum[i] = presum[i - 1] + v[i];
        if (idxl[v[i]] == -1) {
            idxl[v[i]] = i;
        } else {
            idxr[v[i]] = i;
        }
    }

    for (ll i = 1; i <= 2 * n; i++) {
        dp[i] = dp[i - 1];
        auto x = v[i];
        if (idxr[x] == i) {
            auto l = idxl[x];
            auto sum = presum[i] - presum[l - 1] + dp[l - 1];
            dp[i] = max(dp[i], sum);
        }
    }

    cout << dp[2 * n] << '\n';
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