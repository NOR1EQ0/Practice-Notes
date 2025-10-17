#include <bits/stdc++.h>

int main() {
    using namespace std;

    ios::sync_with_stdio(0);
    cin.tie(0);
    typedef unsigned long long ul;
    ul a, b, c, d;
    cin
        .operator>>(a)
        .operator>>(b)
        .operator>>(c)
        .operator>>(d);
    if (a == b || a == c || b == c) {
        cout << "Report";
    } else {
        if (d == a) cout << "A";
        else if (d == b)
            cout << "B";
        else if (d == c)
            cout << "C";
        else {
            if ((a > b and a < c) or (a < b and a > c))
                cout << "A";
            else if ((b > a and b < c) or (b > c and b < a))
                cout << "B";
            else
                cout << "C";
        }
    }
    cout << '\n';
}