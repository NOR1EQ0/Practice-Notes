#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;

int grid[300][300];
char buffer[300];

struct point {
    int x;
    int y;
    bool operator<(const point& other) {
        return x < other.x && y < other.y;
    }
};
static inline void solve() {
    ll n, m;
    cin >> n >> m;
    bool hasone = false;
    for (int i = 1; i <= n; i++) {
        cin >> buffer;
        for (int j = 1; j <= m; j++) {
            grid[i][j] = buffer[j - 1] - '0';
            if (buffer[j - 1] == '1') {
                hasone = true;
            }
        }
    }
    if (!hasone) {
        cout << "0 0 0\n";
        return;
    }
    map<point, point> m4;
    map<point, point> m8;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            if (grid[i][j]) {
                
            }
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