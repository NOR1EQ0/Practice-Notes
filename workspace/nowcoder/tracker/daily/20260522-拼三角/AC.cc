#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;
bool triangle(ll a, ll b, ll c) {
    return a + b > c && a + c > b && b + c > a;
}
static inline void solve() {
    ll lines[6];
    for (ll& i : lines) cin >> i;
    sort(lines, lines + 6);
    do {
        if (triangle(lines[0], lines[1], lines[2]) && triangle(lines[3], lines[4], lines[5])) {
            cout << "Yes\n";
            return;
        }
    } while (next_permutation(lines, lines + 6));
    cout << "No\n";
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