#include <bits/stdc++.h>

using namespace std;

int pascal[40][40]{};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    pascal[1][1] = 1;
    int n;
    cin >> n;
    cout << "1\n";
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
            cout << pascal[i][j] << ' ';
        }
        cout << '\n';
    }
}