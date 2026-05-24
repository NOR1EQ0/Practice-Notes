#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;
static inline void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    set<int> s;
    int mn = 1e9, mx = -1;
    for (auto& i : v) {
        cin >> i;
        mx=max(mx,i);
        mn=min(mn,i);
    }
    cout << mx-mn << '\n';
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