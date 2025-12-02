#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int x, l, r;
    cin >> x >> l >> r;
    cout << boolalpha;
    if (x >= l and x <= r) {
        cout << true;
    } else
        cout << false;
}