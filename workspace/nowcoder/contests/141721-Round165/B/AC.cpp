#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;
static inline void solve() {
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    for (ll i = 1; i <= n; i++) {
        ll num;
        cin >> num;
        if ((num + i) % k == 0) {
            ans++;
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