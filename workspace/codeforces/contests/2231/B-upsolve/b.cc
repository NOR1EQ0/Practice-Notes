#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;
static inline void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto& i : v) cin >> i;
    vector<ll> s(n);
    for (int i = 0; i + 1 < n; i++) {
        if (v[i] > v[i + 1]) {
            if (s[i] == 1 || s[i + 1] == -1) {
                cout << "NO\n";
                return;
            }
            s[i] = -1;
            s[i + 1] = 1;
        }
    }
    ll last{};
    for (auto& i : s) {
        if (i != 0) last = i;
        else
            i = last;
    }

    last = 0;
    for (auto it = s.rbegin(); it != s.rend(); it++) {
        if (*it != 0) last = *it;
        else
            *it = last;
    }

    ll l{}, r = 1e18;
    for (int i = 0; i + 1 < n; i++) {
        if (s[i] == -1 && s[i + 1] == -1) {
            if (s[i] > s[i + 1]) {
                cout << "NO\n";
                return;
            }
        } else if (s[i] == 1 && s[i + 1] == 1) {
            if (s[i] > s[i + 1]) {
                cout << "NO\n";
                return;
            }
        } else if (s[i] == -1 && s[i + 1] == 1) {
            l = max(l, v[i] - v[i + 1]);
        } else if (s[i] == 1 && s[i + 1] == -1) {
            r = min(r, v[i + 1] - v[i]);
        }
    }

    cout << (l <= r ? "YES\n" : "NO\n");
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