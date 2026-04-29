#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int m, a, b, c;
        cin >> m >> a >> b >> c;
        int a_row = min(a, m);
        if (a_row - a > 0) {
            if (a_row - a <= c) {
                c -= (a_row - a);
                a_row = m;
            } else {
                a_row += c;
                c = 0;
            }
        }
        int b_row = min(b, m);
        if (b_row - b > 0) {
            if (b_row - b <= c) {
                c -= (b_row - b);
                b_row = m;
            } else {
                b_row += c;
                c = 0;
            }
        }
        cout << a_row + b_row << '\n';
    }
}