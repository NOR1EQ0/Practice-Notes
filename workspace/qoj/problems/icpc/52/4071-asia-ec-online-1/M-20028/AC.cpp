#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;
static inline void solve() {
    ll n, m;
    cin >> n >> m;
    map<size_t, bool> roster;
    string s;
    while (n--) {
        cin >> s;
        roster[hash<string>()(s)] = false;
    }
    while (m--) {
        cin >> s;
        auto code = hash<string>()(s);
        if (roster.count(code)) {
            if (roster[code]) {
                cout << "REPEAT\n";
            } else {
                cout << "OK\n";
                roster[code] = true;
            }
        } else {
            cout << "WRONG\n";
        }
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