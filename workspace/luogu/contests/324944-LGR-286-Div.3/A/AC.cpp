#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;

static inline void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> scores(n), tusage(n);
    for (auto& i : scores) cin >> i;
    for (auto& i : tusage) cin >> i;

    for (int i = 0; i < n; i++) {
        auto t = tusage[i];
        auto a = scores[i];
        auto mx_r = 30 * a / 100;
        if (mx_r >= m) {
            cout << "inf ";
            continue;
        }
        auto mx_l_const = (250 - t) * a / 250 + 50;
        auto diff = m - mx_l_const;
        if (diff < 0) {
            auto times = abs(m - mx_l_const) / 50;
            auto remind = abs(m - mx_l_const) / 50;
            cout << times;
        } else {
            cout << '0';
        }
        cout << ' ';
    }
    cout << '\n';
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