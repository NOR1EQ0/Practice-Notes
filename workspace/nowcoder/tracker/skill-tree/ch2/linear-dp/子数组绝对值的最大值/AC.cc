#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;
static inline void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    vector<ll> mxdp(n + 1);
    vector<ll> mndp(n + 1);
    mxdp[1] = v[1];
    mndp[1] = v[1];
    for (int i = 2; i <= n; i++) {
        mxdp[i] = max(v[i], mxdp[i - 1] + v[i]);
        mndp[i] = min(v[i], mndp[i - 1] + v[i]);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, max(abs(mxdp[i]), abs(mndp[i])));
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