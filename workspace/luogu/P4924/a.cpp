#include <bits/stdc++.h>

using namespace std;

int magic[501][501];
int tmp[501][501];
int n, m, x, y, r, z;

inline void init() {
    int n2 = n * n;
    int start = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            magic[i][j] = start;
            start++;
        }
    }
}

inline void printmagic() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            cout << magic[i][j] << ' ';
        }
        cout << magic[i][n - 1] << '\n';
    }
}

void rotate() {
    x--, y--; // Correct the position
    int operN = 2 * r + 1;
    // Copy the ranges to be operated
    for (int i = x; i < x + operN; ++i) {
        for (int j = y; j < y + operN; ++j) {
            tmp[i - x][j - y] = magic[i][j];
        }
    }
    if (z) { // Reverse
        // TODO
    } else {
        // TODO
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    while (m--) {
        cin >> x >> y >> r >> z;
    }
    printmagic();
    return 0;
}