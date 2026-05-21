#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;
struct section {
    ll start;
    ll end;
    ll diff;
};
static inline void solve() {
    ll n;cin>>n;
    vector<ll> v(n);
    for (auto& i : v) cin >> i;
    vector<section> secv;
    secv.reserve((int)2e5);
    ll maxdiff = -1;
    for (ll i = 0; i < n; i++) {
        if (i + 1 < n && v[i + 1] < v[i]) {
            // Start to maintain a section;
            secv.emplace_back(i, i + 2, v[i] - v[i + 1]);
            auto& sec = secv.back();
            while (sec.end < n) {
                if (v[sec.end] >= v[sec.start]) {
                    break;
                } else {
                    auto cur_diff = v[sec.start] - v[sec.end];
                    if (cur_diff > 0) {
                        sec.diff = max(cur_diff, sec.diff);
                    }
                    sec.end++;
                }
            }
            maxdiff = max(maxdiff, sec.diff);
            i = sec.end - 1;
        }
    }
    bool lastadd = true;
    for (auto& sec : secv) {
        if (sec.end == n) {
            lastadd = false;
        }
        for (auto i = sec.start + 1; i < sec.end; i++) {
            v[i] += maxdiff;
        }
    }
    if (lastadd) v.back() += maxdiff;
    auto ans = ranges::is_sorted(v);
    cout << (ans ? "YES\n" : "NO\n");
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