#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        if (a > 60 or b > 60) {
            cout << "-1\n";
        }
        if (a > 23) {
            if (b > 23) {
                cout << "-1\n";
            } else {
                cout << b << ' ' << a << '\n';
            }
        } else if (b > 23) {
            if (a > 23) {
                cout << "-1\n";
            } else {
                cout << a << ' ' << b << '\n';
            }
        }
        
    }
}