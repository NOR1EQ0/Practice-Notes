#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    bool odd = n % 2;
    for (int i = 0; i < n / 2; i++) {
        cout << n - i << ' ';
        cout << i + 1 << ' ';
    }
    if (odd) cout << (n + 1) / 2 << '\n';
}