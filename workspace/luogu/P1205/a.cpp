#include <bits/stdc++.h>

using namespace std;

#define Reflect do { \
    /* code */ \
} while (false);
#define pmsg(x) do{if(!cmpChange){cout<<#x<<'\n';return 0;}}while(false)

char square[10][10];
char target[10][10];
int n;

inline bool cmpImage(char value[10][10]) {
    for (int i = 0; i < n; ++i) {
        auto cmp = memcmp(value[i], target[i], n);
        if (!cmp) return true;
    }
    return false;
}

int main() {
    // 1-7 Rotate90 Rotate180 Rotate270 Reflect GroupIt Remain Unavailable
    // 67
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    // read 2 squares
    for (int i = 0; i < n; ++i) {
        cin >> square[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> target[i];
    }

    // 6 Remain
    bool cmpChange = cmpImage(square);
    pmsg(6);

    // 1 Rotate90
    for (int i = 0; i < n; ++i) {
        bool diff = false;
        for (int j = 0; j < n; ++j) { if (square[i][j] != target[j][n - i - 1]) { diff = true; break; } }
        if (diff) { cmpChange = false; break; }
    }
    pmsg(1);

    // 2 Rotate180
    for (int i = 0; i < n; ++i) {
        bool diff = false;
        for (int j = 0; j < n; ++i) { if (square[i][j] != target[n - i - 1][n - j - 1]) { diff = true; break; } }
        if (diff) { cmpChange = false; break; }
    }
    pmsg(2);

    // 3 Rotate270
    // todo

    // 7 Unavailable
    cout << "7\n";
    return 0;
}