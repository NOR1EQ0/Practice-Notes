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
#if 0
struct dsu {
    vector<ll> arr;

    template <typename T, typename = enable_if_t<is_integral_v<T>>>
    explicit dsu(T __n) : arr(__n + 1) { iota(arr.begin(), arr.end(), 0); }

    size_t find(size_t __target) {
        return arr[__target] == __target ? __target : arr[__target] = find(arr[__target]);
    }

    void unite(size_t __t1, size_t __t2) {
        auto lhs = find(__t1);
        auto rhs = find(__t2);
        arr[lhs] = rhs;
    }
};
#endif
class DSU {
private:
    vector<ll> parent, rank, size;

public:
    DSU(ll n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 1);
        size.resize(n + 1, 1);
        for (ll i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    ll find(ll p) {
        if (parent[p] != p) parent[p] = find(parent[p]);
        return parent[p];
    }
    void unite(ll p, ll q) {
        ll rootP = find(p);
        ll rootQ = find(q);
        if (rootP == rootQ) return;
        if (rank[rootP] > rank[rootQ]) {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        } else if (rank[rootP] < rank[rootQ]) {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        } else {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
            rank[rootP] += 1;
        }
    }
    bool connected(ll x, ll y) {
        return find(x) == find(y);
    }
    ll getSize(ll p) {
        return size[find(p)];
    }
    ll count() {
        ll ans = 0;
        for (ll i = 0; i < parent.size(); i++) {
            ans += (parent[i] == i);
        }
        return ans;
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
    auto checkBoundary = [&](ll x, ll y) -> bool {
        return x > 0 && y > 0 &&
               x <= n && y <= n;
    };
    DSU dsu4((n + 1) * (m + 1) + 1), dsu8((n + 1) * (m + 1) + 1);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            if (grid[i][j]) {
                for (int xoff = -1; xoff <= 1; xoff++) {
                    for (int yoff = -1; yoff <= 1; yoff++) {
                        int nx;
                        int ny;
                        if ((!xoff && !yoff) || !checkBoundary(nx = i + xoff, ny = j + yoff)) {
                            continue;
                        }
                        if (grid[nx][ny]) {
                            dsu8.unite(i * m + j, nx * m + ny);
                            if ((bool)xoff != (bool)yoff) {
                                dsu4.unite(i * m + j, nx * m + ny);
                            }
                        }
                    }
                }
            }
        }
    }
    ll c4{}, c8{}, s4{}, s8{};
    vector<ll> memo4((n + 1) * (m + 1) + 1), memo8((n + 1) * (m + 1) + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!grid[i][j]) continue;
            memo4[dsu4.find(i * m + j)]++;
            memo8[dsu8.find(i * m + j)]++;
        }
    }
    for (int i = 1; i <= n * m; i++) {
        c4 += (memo4[i] != 0);
        c8 += (memo8[i] != 0);
        s4 = max(s4, memo4[i]);
        s8 = max(s8, memo4[i]);
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