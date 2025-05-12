#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    using ll = int64_t;
    ll tmp;
    cin >> tmp;
    if (tmp > 2025) {
        cout << "YES\n";
    } else if (tmp == 2025) {
        cout << "=\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}