#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int an, bn;
        cin >> an >> bn;
        deque<int> a(an), b(bn);
        for (int i = 0; i < an; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < bn; i++) {
            cin >> b[i];
        }
        int awin = 0, bwin = 0;
        while (!a.empty() && !b.empty()) {
            auto a_curr = a.front(),
                 b_curr = b.front();
            if (a_curr > b_curr) {
                awin++;
                a.push_back(a.front());
            } else if (a_curr < b_curr) {
                bwin++;
                b.push_back(b.front());
            }
            a.pop_front();
            b.pop_front();
        }

        if (awin == bwin) {
            cout << "draw\n";
        } else {
            cout << (awin > bwin ? "alice\n" : "bob\n");
        }
    }
    return 0;
}