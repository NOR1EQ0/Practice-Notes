#include <bits/stdc++.h>

using namespace std;

char layout[105][105];
int n = 1, m = 1;

bool single_tree(int i, int j) {
    int di[8] = {-1, 0, 1, -1, 1, -1, 0, 1},
        dj[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    for (int k = 0; k < 8; k++) {
        int ti = i + di[k];
        int tj = j + dj[k];
        if (ti >= 0 && ti <= n - 1 && tj >= 0 && tj <= m - 1) {
            di[k] = ti, dj[k] = tj;
        } else {
            di[k] = dj[k] = INT_MIN;
        }
    }
    for (int k = 0; k < 8; k++) {
        auto &ti = di[k], &tj = dj[k];
        if (ti == INT_MIN || tj == INT_MIN) continue;
        if (layout[ti][tj] == '@') return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    while (cin >> n >> m, n || m) {
        size_t cnt{};
        for (int i = 0; i < n; i++) {
            cin >> layout[i];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (layout[i][j] == '*') continue;
                if (single_tree(i, j)) cnt++;
            }
        }
        cout << cnt << '\n';
        memset(layout, 0, sizeof(layout));
    }
}