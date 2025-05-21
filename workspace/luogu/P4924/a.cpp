#include <bits/stdc++.h>

using namespace std;

int magic[501][501];
int tmp[501][501];
// int magic[5][5];
// int tmp[5][5];
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
    int corner[4] = {
        x - r /*L*/, x + r /*R*/,
        y - r /*T*/, y + r /*B*/
    };
    /**
     * +---------+>x
     * |    T2  v|
     * |         |
     * |L0  *  1R|
     * |         |
     * |A   B3   |
     * +---------+
     * v
     * y
     */
     // Copy the ranges to be operated
    for (int i = corner[0]; i <= corner[1]; ++i) {
        for (int j = corner[2]; j <= corner[3]; ++j) {
            tmp[i - corner[0]][j - corner[2]] = magic[i][j];
        }
    }

    if (z == 1) { // Reverse
        for (int curx = corner[0]; curx <= corner[1]; curx++) {
            for (int cury = corner[3]; cury >= corner[2]; cury--) {
                magic[cury][curx] = tmp[curx - corner[0]][corner[3] - cury];
            }
        }
    } else {
        for (int curx = corner[1]; curx >= corner[0]; curx--) {
            for (int cury = corner[2]; cury <= corner[3]; cury++) {
                magic[cury][curx] = tmp[corner[1] - curx][cury - corner[2]];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    init();
    while (m--) {
        cin >> x >> y >> r >> z;
        rotate();
        // printmagic();cout<<'\n';
    }
    printmagic();
    return 0;
}