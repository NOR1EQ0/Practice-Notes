#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    string x;
    int m, k;
    cin >> n >> x >> m >> k;
    if (k == n) {
        cout << "mei you mai ";
    } else if (k == m) {
        cout << "kan dao le mai ";
    } else {
        cout << "wang le zhao mai ";
    }
    cout << x << " de\n";
}