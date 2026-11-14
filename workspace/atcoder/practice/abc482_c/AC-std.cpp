#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;
static inline void solve() {
    ll h, w, n, q;
    cin >> h >> w >> n >> q;
    vector<ll> rv, cv;
    rv.reserve(n), cv.reserve(n);
    while (n--) {
        ll x,y;
        cin>>x>>y;
        rv.push_back(x),cv.push_back(y);
    }
    ranges::sort(rv);
    ranges::sort(cv);
    while (q--) {
        int cmd;
        cin >> cmd;
        ll u, d, l, r;
        if (cmd == 1) {
            cin >> u >> d;
            cout << ranges::upper_bound(rv, d) - ranges::lower_bound(rv, u);
        } else {
            cin >> l >> r;
            cout << ranges::upper_bound(cv, r) - ranges::lower_bound(cv, l);
        }
        cout << '\n';
    }
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