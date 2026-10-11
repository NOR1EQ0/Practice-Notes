#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;
static inline void solve() {
    ll n;
    string s;
    cin >> n >> s;
    ll ans = 0;
    ll rainy = 0;
    for (auto c: s) {
        if (c == 'R') {
            rainy++;
        } else {
            ans = max(ans, rainy);
            rainy = 0;
        }
    }
    ans = max(ans, rainy);
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