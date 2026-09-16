#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;
int grid[300][300];
char buffer[300];
struct dsu {
    vector<ll> parent, rank, size;
    dsu(size_t __n) : parent(__n + 1), rank(__n + 1, 1), size(__n + 1, 1) {
        iota(parent.begin(), parent.end(), 0ll);
    }
    ll find(ll p) {
        if (parent[p] != p) parent[p] = find(parent[p]);
        return parent[p];
    }
    void unite(ll p, ll q) {
        auto rootp = find(p);
        auto rootq = find(q);
        if (rootp == rootq) return;
        if (rank[rootp] > rank[rootq]) {
            parent[rootq] = rootp;
            size[rootp] += size[rootq];
        } else if (rank[rootp] < rank[rootq]) {
            parent[rootp] = rootq;
            size[rootq] += size[rootp];
        } else {
            parent[rootq] = rootp;
            size[rootp] += size[rootq];
            rank[rootp]++;
        }
    }
};
static inline void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> buffer;
        transform(buffer, buffer + m, grid[i], [](auto&& c) -> int { return c - '0'; });
    }
    dsu dsu4(n * m + 1), dsu8(n * m + 1);
    auto checkBoundary = [&](int x, int y) {
        return x >= 0 && y >= 0 &&
               x < n && y < m;
    };
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (grid[x][y]) {
                for (int xoff = -1; xoff <= 1; xoff++) {
                    for (int yoff = -1; yoff <= 1; yoff++) {
                        int nx, ny;
                        if ((!xoff && !yoff) || !checkBoundary(nx = x + xoff, ny = y + yoff)) {
                            continue;
                        }
                        if (grid[nx][ny]) {
                            dsu8.unite(x * m + y, nx * m + ny);
                            if ((bool)xoff != (bool)yoff) {
                                dsu4.unite(x * m + y, nx * m + ny);
                            }
                        }
                    }
                }
            }
        }
    }
    ll c4{}, c8{}, s4{}, s8{};
    vector<ll> memo4(n * m + 1), memo8(n * m + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!grid[i][j]) {
                continue;
            }
            memo4[dsu4.find(i * m + j)]++;
            memo8[dsu8.find(i * m + j)]++;
        }
    }
    for (int i = 0; i < n * m; i++) {
        c4 += (memo4[i] != 0);
        c8 += (memo8[i] != 0);
        s4 = max(s4, memo4[i]);
        s8 = max(s8, memo8[i]);
    }
    cout << format("{} {} {}\n", c4 - c8, s4, s8);
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