#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        bool flg{};
        if (a ^ b) { // Only have one of two
            if (a and !(a % 2)) {
                flg = 1;
            }
            if (b and !(b % 2)) {
                flg = 1;
            }
        } else {
            if (!(a % 2)) {
                auto rest = b - a / 2;
                if (rest % 2) {} else flg = 1;
            }
        }
        cout << (flg ? "YES\n" : "NO\n");
    }
}