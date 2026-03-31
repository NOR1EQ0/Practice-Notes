#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int __T;
    cin >> __T;
    while (__T--) {
        string l, r;
        cin >> l >> r;
        string t(1, '1');
        int n = r.size();
        for (int i = 0; i < n - 1; i++) {
            t += '0';
        }

        if (r == t) {
            if (l == r) {
                cout << "1\n";
            } else {
                auto x = stoll(r);
                cout << x - 1 << '\n';
            }
            continue;
        }

        if (l.size() < r.size()) {
            l = t;
            l.back() += 1;
            assert(l.size() == r.size());
        }

        int k = -1;
        for (int i = 0; i < n; i++) {
            if (l[i] != r[i]) {
                k = i;
                break;
            }
        }

        if (k == -1) {
            string_view sv = r;
            auto head = sv.find_first_not_of('0');
            if (head == string::npos) {

            } else {
                
            }
        }
    }
}