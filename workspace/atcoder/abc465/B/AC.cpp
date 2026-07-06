#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;
static inline void solve() {
    int x, y, l, r, a, b;
    cin >> x >> y >> l >> r >> a >> b;
    int ans{};
    if (a < l) {
        ans += (min(l,b) - a) * y;
    }

    int L = clamp(a, l, r);
    int R = clamp(b, l, r);
    ans += (R - L) * x;

    if (b > r) {
        ans += (b - max(a, r)) * y;
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