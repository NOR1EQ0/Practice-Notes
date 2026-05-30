#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;
using ld = long double;
static inline void solve() {
    ld x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    auto distance = sqrtl((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    auto rsum = r1 + r2;
    auto rdiff = fabs(r1 - r2);
    if (distance <= rsum && distance >= rdiff) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}
int main() {
#if defined(ONLINE_JUDGE) || 0
    ios::sync_with_stdio(0), cin.tie(0);
#elif 0
    freopen("1.in", "rb", stdin);
#endif
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}