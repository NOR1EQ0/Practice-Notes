#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;
static inline void solve() {
    ll n;
    cin >> n;
    vector<int> v(n);
    for (auto& i : v) {
        cin >> i;
    }
    int l = 0, r = n - 1;
    for (; l < n; l++) {
        if (v[l]) {
            v[l] = 1;
            break;
        }
    }
    for (; r >= 0; r--) {
        if (v[r]) {
            v[r] = 1;
            break;
        }
    }
    for (int i = l + 1; i < r; i++) {
        if (v[i] == -1) {
            v[i] = 0;
        }
    }
printans:
    for (auto i : v) cout << i << ' ';
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