#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;
static inline void solve() {
    ll n, w;
    cin >> n >> w;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    ll ans = 0;
    for (ll i = 0; i < 1 << n; i++) {
        ll taste{}, cost{};
        for (ll j = 0; j < n; j++) {
            if (i >> j & 1) {
                taste += a[j], cost += b[j];
            }
        }
        if (cost <= w) {
            ans = max(ans, taste);
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