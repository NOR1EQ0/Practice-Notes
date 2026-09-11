#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;
struct edge {
    ll u, v;
};
static inline void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> lv(m), rv(m);
    vector<edge> graph;
    for (ll i = 0; i < m; i++) {
        auto edgecnt = rv[i] - lv[i] + 1;
    }
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