#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;
static inline void solve() {
    ll h, w, n, q;
    cin >> h >> w >> n >> q;
    vector<ll> rowcnt(h+1), colcnt(w+1);
    while (n--) {
        ll x,y;
        cin>>x>>y;
        rowcnt[x]++, colcnt[y]++;
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