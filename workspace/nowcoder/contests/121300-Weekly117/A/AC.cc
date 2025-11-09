#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int a,b;
    cin >> a >> b;
    string res;
    if (a == 1) {
        if (b == 1) {
            res = "LU";
        } else {
            res = "LD";
        }
    } else {
        if (b == 1) {
            res = "RU";
        } else {
            res = "RD";
        }
    }
    cout << res << '\n';
}