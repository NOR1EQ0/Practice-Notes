#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;
static inline void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n + 1), dp(n + 1), pref(n + 1);
    dp[0] = pref[0] = 1;
    ll orval = 0;
    ll wndl = 1;
    // for (auto& i : v) cin >> i;
    for (int i = 1; i <= n; i++) cin >> v[i]; // read

    for (ll i = 1; i <= n; i++) {
        while ((orval & v[i]) != 0) {
            orval ^= v[wndl];
            ++wndl;
        }
        orval |= v[i];
        ll sum = pref[i-1];
        if (wndl >= 2) sum = (sum - pref[wndl - 2] + MOD) % MOD;
        dp[i] = sum;
        pref[i] = (dp[i] + pref[i-1]) % MOD;
    }

    cout << dp[n] << '\n';
}
int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    0;
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}