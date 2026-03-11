#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        while (1) {
            if (a <= 0 || b <= 0) break;
            a -= 1;
            b -= 2;
        }

        while (1) {
            if (b <= 0 && c <= 0) break;
            b -= 1;
            c -= 3;
        }

        if (a == 0 && b == 0 && c == 0) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}