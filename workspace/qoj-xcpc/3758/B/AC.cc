#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;
char ansitable[256];
#if 1
#define num first
#define ch second
#endif
static inline void solve() {
    using PIC = pair<int, char>;
    int n;
    cin >> n;
    n *= 4;
    vector<PIC> v(n);
    for (auto& [x, y] : v) cin >> x >> y;
    for (int i = 0; i < n; i++) {
        bool swpflg = false;
        for (int j = 1; j < n; j++) {
            if (v[j].num == v[j - 1].num) {
                if (ansitable[v[j].ch] < ansitable[v[j - 1].ch]) {
                    swap(v[j], v[j - 1]);
                    swpflg = true;
                }
            }
        }
        if (!swpflg) break;
    }

    auto ret = ranges::is_sorted(v, [&](PIC& lhs, PIC& rhs) -> bool {
        return ansitable[lhs.ch] < ansitable[rhs.ch];
    });

    cout << (ret ? "YES\n"sv : "NO\n"sv);
}

void locall() {
#if !(defined(ONLINE_JUDGE)) && 0
    freopen("1.in", "rb", stdin);
#endif
}

int main() {
    locall();
#define settable(c, x) ansitable[c] = x
    settable('R', 1);
    settable('Y', 2);
    settable('G', 3);
    settable('B', 4);
#undef settable
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    0;
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}