#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll digitsum(string_view sv) {
    ll ret = 0;
    for (auto c: sv) {
        if (!isdigit(c)) throw "fuck";
        ret += (c - '0');
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll x;
        cin >> x;
        if (x < 10) {
            cout << "0\n";
        } else {
            auto xsum = digitsum(to_string(x));
            auto ystr = to_string(xsum + x);
            auto y = stoll(ystr);
            auto ysum = digitsum(ystr);
            auto res = y - ysum;
            if (res == x) {
                cout << "10\n";
            } else {
                cout << "0\n";
            }
        }
    }
}