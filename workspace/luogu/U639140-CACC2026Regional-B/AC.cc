#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr auto MAXN = 2005;

ll forest[MAXN][MAXN];

// 必须将其复制到你的代码中
struct RandomGenerator {
    long long seed;

    // 构造函数，传入题目给定的 seed
    RandomGenerator(long long _seed) : seed(_seed) {}

    // 每次调用生成下一个数字
    int next() {
        // 简单的线性同余生成规则
        seed = (seed * 11 + 3) % 100;
        return (int)seed;
    }
};

int main() {
    // ios::sync_with_stdio(0), cin.tie(0);
    int n, m, seed;
    cin >> n >> m >> seed;
    RandomGenerator rg(seed);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            forest[i][j] = rg.next();
        }
    }

    // Forest Preview
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << forest[i][j] << " \n"[j == m - 1];
    //     }
    // }
    // return 0;

    // Start: (n - 1, 0), Destination: (0, m - 1)
    // Offset: Right (->): (0, +1) | Upward (A): (-1, 0)

    vector<vector<ll>> dp(n, vector<ll>(m));

    ll maxcnt = 0;

    for (int x = n - 1; x >= 0; x--) {
        for (int y = 0; y < m; y++) {
            ll dpnum = 0;
            if (x < n - 1) {
                dpnum = dp[x + 1][y];
            }
            if (y > 0) {
                dpnum = max(dpnum, dp[x][y - 1]);
            }
            dp[x][y] = forest[x][y] + dpnum;
            maxcnt = max(maxcnt, dp[x][y]);
        }
    }

    // DP Preview
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << dp[i][j] << " \n"[j == m - 1];
    //     }
    // }

    cout << maxcnt << '\n';
}