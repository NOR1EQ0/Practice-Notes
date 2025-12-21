#include <bits/stdc++.h>

using namespace std;

struct point {
    int row;
    int col;
} pts[100];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int h, w, n;
    int cnt = 0;
    cin >> h >> w >> n;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int tmp;
            cin >> tmp;
            pts[tmp] = {i+1, j+1};
        }
    }

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        pts[tmp] = {pts[tmp].row, -1};
    }

    unordered_map<int, int> umap;

    for (auto i : pts) {
        if (i.row && i.col == -1) {
            umap[i.row]++;
        }
    }
    for (auto i: umap) {
        cnt = max(cnt, i.second);
    }

    cout << cnt << '\n';
}