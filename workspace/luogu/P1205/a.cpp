#include <bits/stdc++.h>

using namespace std;

// Print if operated matrix matches target
#define pmsg(x) do{if(!cmpChange){cout<<#x<<'\n';return 0;}cmpChange=false;}while(false)

char square[10][10];
char target[10][10];
char reflect[10][10];
int n;

inline bool cmpImage(char value[10][10]) {
    for (int i = 0; i < n; ++i) {
        auto cmp = memcmp(value[i], target[i], n);
        if (cmp) return true;
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

    bool cmpChange = false;

    // 1 Rotate90
    for (int i = 0; i < n; ++i) {
        bool diff = false; for (int j = 0; j < n; ++j) { if (square[i][j] != target[j][n - i - 1]) { diff = true; break; } } if (diff) { cmpChange = true; break; }
    }
    pmsg(1);

    // 2 Rotate180
    for (int i = 0; i < n; ++i) {
        bool diff = false; for (int j = 0; j < n; ++j) { if (square[i][j] != target[n - i - 1][n - j - 1]) { diff = true; break; } } if (diff) { cmpChange = true; break; }
    }
    pmsg(2);

    // 3 Rotate270
    for (int i = 0; i < n; ++i) {
        bool diff = false; for (int j = 0; j < n; ++j) { if (square[i][j] != target[n - j - 1][i]) { diff = true; break; } } if (diff) { cmpChange = true; break; }
    }
    pmsg(3);

    // 4 Reflect
    for (int i = 0; i < n; ++i) {
        memcpy(reflect[i], square[n-i-1], n);
    }
    cmpChange = cmpImage(reflect);
    pmsg(4);

    // 5 GroupIt
    for (int i = 0; i < n; ++i) { // 90
        bool diff = false; for (int j = 0; j < n; ++j) { if (reflect[i][j] != target[j][n - i - 1]) { diff = true; break; } } if (diff) { cmpChange = true; break; }
    }
    pmsg(5);
    for (int i = 0; i < n; ++i) { // 180
        bool diff = false; for (int j = 0; j < n; ++j) { if (reflect[i][j] != target[n - i - 1][n - j - 1]) { diff = true; break; } } if (diff) { cmpChange = true; break; }
    }
    pmsg(5);
    for (int i = 0; i < n; ++i) { // 270
        bool diff = false; for (int j = 0; j < n; ++j) { if (reflect[i][j] != target[n - j - 1][i]) { diff = true; break; } } if (diff) { cmpChange = true; break; }
    }
    pmsg(5);

    // 6 Ramain
    cmpChange = cmpImage(square);
    pmsg(6);

    // 7 Unavailable
    cout << "7\n";
    return 0;
}