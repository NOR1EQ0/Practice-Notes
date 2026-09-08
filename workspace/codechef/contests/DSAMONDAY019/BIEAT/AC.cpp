#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;
static inline void solve() {
    ull n;
    cin >> n;
    vector<ull> v(n);
    for (auto&& i : v) cin >> i;
    ull m;
    cin >> m;
    for (auto i : v) cout << (i >> m) << ' ';
    cout << '\n';
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