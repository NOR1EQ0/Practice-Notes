#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;
static inline void solve() {
    ll n;
    cin >> n;
    if (n == 1) {
        cout << "1 0\n";
        return;
    }
    vector<ll> v(n);
    vector<ll> pts = {0};
    cin >> v[0];
    ll mx = v[0];
    for (ll i = 1; i < n; i++) {
        cin >> v[i];
        if (v[i] > mx) {
            mx = v[i];
            pts.push_back(i);
        }
    }
    if (pts.size() < 2) {
        cout << "1 0\n";
        return;
    }
    ll mxdiff = 0;
    for (int i = 1; i < pts.size(); i++) {
        mxdiff = max(mxdiff, pts[i] - pts[i - 1]);
    }
    cout << pts.size() << ' ' << mxdiff << '\n';
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