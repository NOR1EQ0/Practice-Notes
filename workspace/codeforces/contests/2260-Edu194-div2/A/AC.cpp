#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;
static inline void solve() {
    ll n;
    cin >> n;
    ll simpleFirst, simpleLast;
    cin >> simpleFirst;
    ll zero{};
    ll tmp;
    for (ll i = 1; i < n - 1; i++) {
        cin >> tmp;
        if (!tmp) {
            zero++;
        }
    }
    cin >> simpleLast;
    if (!simpleFirst && !simpleLast) {
        cout << "0\n";
        return;
    }
    if (simpleFirst + simpleLast <= zero) {
        cout << simpleFirst + simpleLast << '\n';
    } else {
        cout << "-1\n";
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