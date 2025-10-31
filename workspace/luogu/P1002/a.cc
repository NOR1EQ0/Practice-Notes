#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int tx, ty, hx, hy;
bool ctrl[25][25];
ll dp[25][25];

void init() {
    ctrl[hx][hy] = 1;
    ctrl[hx + 2][hy - 1] = 1;
    ctrl[hx + 2][hy + 1] = 1;
    ctrl[hx + 1][hy - 2] = 1;
    ctrl[hx + 1][hy + 2] = 1;
    ctrl[hx - 1][hy - 2] = 1;
    ctrl[hx - 1][hy + 2] = 1;
    ctrl[hx - 2][hy - 1] = 1;
    ctrl[hx - 2][hy + 1] = 1;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> tx >> ty >> hx >> hy;
    if (ctrl[0][0]) {
        cout << 0 << '\n';
        return 0;
    }
    init();
    dp[0][0] = 1;

    for (int x = 0; x <= tx; x++) {
        for (int y = 0; y <= ty; y++) {
            if (ctrl[x][y]) {
                dp[x][y] = 0;
                continue;
            }
            if (x == 0 and y == 0) continue;
            if (x > 0) dp[x][y] += dp[x - 1][y];
            if (y > 0) dp[x][y] += dp[x][y - 1];
        }
    }

    cout << dp[tx][ty] << '\n';
}