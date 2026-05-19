#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;
static inline void solve() {
    ll n, a, b;
    cin >> n >> a >> b;
    ll ans = 0;
    if (b / 3 > a) {
        cout << a * n << '\n';
    } else {
        ll threecnt = n / 3;
        if (threecnt > 0) {
            ans += threecnt * b;
            n %= 3;
        } else {
            cout << min(a * n, b) << '\n';
        }
    }
}
int main() {
#if !(defined(ONLINE_JUDGE)) && 1
    ios::sync_with_stdio(0), cin.tie(0);
#elif 0
    freopen("1.in", "rb", stdin);
#endif
    0;
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}