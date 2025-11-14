#include <bits/stdc++.h>

using namespace std;
using PII = pair<int, int>;

char layout[105][105];
const int di[8] = {-1, 0, 1, -1, 1, -1, 0, 1},
          dj[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int n = 1, m = 1;

map<PII, PII> forests;

PII find_a_forest(int i, int j) {
    PII positions[8];
    for (int k = 0; k < 8; k++) {
        int ti = i + di[k];
        int tj = j + dj[k];
        if (ti >= 0 && ti < n && tj >= 0 && tj < m) {
            positions[k] = {ti, tj};
        } else {
            positions[k] = {INT_MIN, INT_MIN};
        }
    }

    for (int k = 0; k < 8; k++) {
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    while (cin >> n >> m, n || m) {
        // forests.reserve(n * m);
        for (int i = 0; i < n; i++) {
            cin >> layout[i];
        }
        forests.clear();
    }
}