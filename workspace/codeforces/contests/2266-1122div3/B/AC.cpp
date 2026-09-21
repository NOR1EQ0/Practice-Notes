#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;
static inline void solve() {
    ll a, b, c;
    cin >> a >> b >> c;

    ll ans = 0;
    if (a < b) {
        if ((b - a) * 2 < c) {
            a += c;
            ans = a - b;
        } else
            ans = b - a;
    } else {
        a += c;
        ans = a - b;
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