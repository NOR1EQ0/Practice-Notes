#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;
static inline void solve() {
    char grid[5][6];
    ll extra = LLONG_MAX;
    for (auto&& str : grid) {
        cin >> str;
        ll cur = ranges::count(str, '.');
        extra = min(cur, extra);
    }
    for (int i = 0; i < 5; i++) {
        ll cur = 0;
        for (int j = 0; j < 5; j++) {
            if (grid[j][i] == '.') {
                cur++;
            }
        }
        extra = min(cur, extra);
    }
    do
    {
        ll cur = 0;
        for (int i = 0; i < 5; i++) {
            if (grid[i][i] == '.') {
                cur++;
            }
        }
        extra = min(cur, extra);
    } while (false);
    cout << extra << '\n';
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