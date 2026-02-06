#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, x, y;
    cin >> n >> x >> y;
    int req = max(x, y) * 2;
    if (req > n) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}