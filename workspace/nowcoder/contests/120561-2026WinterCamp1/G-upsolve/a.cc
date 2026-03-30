#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string l, r;
        cin >> l >> r;
        if (l == r) {
            reverse(r.begin(), r.end());
            cout << stoll(r) << '\n';
            continue;
        }

        if (r.front() == '1') {
            auto siz = r.size();
            bool flag = true;
            for (int i = 1; i < siz; i++) {
                if (r[i] != '0') {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                siz--;
                for (int i = 0; i < siz; i++) {
                    cout << '9';
                }
                cout << '\n';
                continue;
            }
        }
    }
}