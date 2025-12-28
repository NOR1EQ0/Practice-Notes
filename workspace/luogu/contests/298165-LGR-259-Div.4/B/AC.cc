#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    if (a) {
        cout << a << '\n';
    } else {
        int m = INT_MAX;
        if (b) m = min(m, b);
        if (c) m = min(m, c);
        cout << m << '\n';
    }
}