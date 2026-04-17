#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int row;
    char c;
    cin >> row >> c;
    int col = row;
    row *= 10;
    row /= 2;
    if (row % 10 < 5) {
        row /= 10;
    } else {
        row = row / 10 + 1;
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << c;
        }
        cout << '\n';
    }
}