#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    string s, p;
    while (t--) {
        cin >> p >> s;
        if (p[0] != s[0]) {
            cout << "NO\n";
            continue;
        }
        ll pcnt{1}, scnt{1};
        ll pidx{}, sidx{};
        bool legal = true;

        while (pidx <= p.length() && sidx <= s.length()) {
            while (pidx && p[pidx] == p[pidx - 1]) {
                pcnt++;
                pidx++;
            }

            while (sidx && s[sidx] == s[sidx - 1]) {
                scnt++;
                sidx++;
            }

            if (p[pidx] != s[sidx] || scnt < pcnt || scnt > pcnt * 2) {
                legal = false;
                break;
            }

            pcnt = scnt = 1;
            pidx++, sidx++;
        }

        if (legal) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}