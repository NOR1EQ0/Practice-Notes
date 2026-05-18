#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;
char ansitable[256];
static inline void solve() {
    using PIC = pair<int, char>;
    int n;
    cin >> n;
    vector<PIC> v(n);
    for (auto& [x, y] : v) cin >> x >> y;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
        }
    }
}
int main() {
#define set(c, x) ansitable[c] = x
    set('R', 1);
    set('Y', 2);
    set('G', 3);
    set('B', 4);
#undef set
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0),
        cin.tie(0);
#endif
    0;
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}