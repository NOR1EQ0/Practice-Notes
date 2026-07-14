#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;
static inline void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> lines;
    bool has_a_line = false;
    for (int i = 0; i < n; i++) {
        if (s[i] == '#') {
            has_a_line = true;
            ll curr = 1;
            for (int j = i + 1; j < n; j++) {
                if (s[j] == '#') {
                    curr++;
                } else {
                    break;
                }
            }
            lines.push_back(curr);
        }
    }
    if (has_a_line) {
        auto mx = *ranges::max_element(lines);
        if (mx <= 2) {
            mx = 1;
        } else {
            bool upper = mx % 2;
            mx = mx / 2 + upper;
        }
        cout << mx << '\n';
    } else {
        cout << "0\n";
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