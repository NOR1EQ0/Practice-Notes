#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;

int offset[][2][2] = {
    {{0, 1}, {1, 0}},
    {{0, 0}, {1, 1}},
    {{0, 0}, {1, 1}},
    {{0, 1}, {1, 0}}};
static inline void solve() {
    char s[2][3];
    cin >> s[0] >> s[1];
    int idx = 0;
    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 1; j++) {
            if (s[i][j] == 'A') {
                idx = i * 2 + j;
            }
        }
    }
    bool ans = false;
    {
        auto& it = offset[idx];
        auto c1 = s[it[0][0]][it[0][1]];
        auto c2 = s[it[1][0]][it[1][1]];
        if (c1 == 'D' || c2 == 'D') {
            ans = true;
        }
    }
    cout << (ans ? "Yes\n": "No\n");
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