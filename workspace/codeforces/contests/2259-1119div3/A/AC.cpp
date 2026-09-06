#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;
static inline void solve() {
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll ans = 0;
    for (ll i = 0; i < n; i += k) {
        const auto ed = i + k;
        bool freeland = 0;
        for (ll j = i; j < ed; j++) {
            if (s[j] == '0') {
                freeland = true;
                break;
            }
        }
        if (!freeland) {
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
    cin >> t;
    while (t--) {
        solve();
    }
}