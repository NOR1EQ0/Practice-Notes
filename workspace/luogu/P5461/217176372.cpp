#include <bits/stdc++.h>

using namespace std;

int arr[1 << 11][1 << 11];

void set_verdict(int x, int y, int n) {
    if (n == 0)
        arr[x][y] = 1;
    else {
        set_verdict(x + (1 << (n - 1)), y, n - 1); // 右上角
        set_verdict(x + (1 << (n - 1)), y + (1 << (n - 1)), n - 1); // 右下角
        set_verdict(x, y + (1 << (n - 1)), n - 1); // 左下角
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin >> n;
    set_verdict(0, 0, n);
    int len = 1 << n;
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}