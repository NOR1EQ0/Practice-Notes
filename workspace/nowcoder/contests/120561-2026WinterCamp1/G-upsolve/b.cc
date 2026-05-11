#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

string l, r;
static inline void solve() {
    cin >> l >> r;
    if (l == r) {
        ranges::reverse(l);
        cout << stoll(l) << '\n';
        return;
    }

    if (ranges::count(r, '0') == r.size() - 1 && r[0] == '1') {
        cout << stoll(r) - 1 << '\n';
        return;
    }

    
}

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    0;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}