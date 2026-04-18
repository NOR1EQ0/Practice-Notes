#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    ll n, p, l, r;
    string s;
    s.reserve(1e6);
    array<size_t, 3> pos;
    string s1, s2;
    cin >> n >> s;
    while (n--) {
        int op;
        cin >> op;
        if (op == 1) {
            cin >> s1;
            // ranges::fill(pos, string::npos); // invalid init
            size_t cur = 0;
            int i = 0;
            for (i = 0; i < 3; i++) {
                auto that = s.find(s1, cur);
                if (that != string::npos) {
                    pos[i] = that;
                    cur = that + 1;
                } else {
                    break;
                }
            }
            if (i) {
                for (int j = 0; j < i; j++) {
                    cout << pos[j];
                    if (j != i - 1) {
                        cout << ' ';
                    }
                }
            } else {
                cout << "-1";
            }
            cout << '\n';
        } else {
            if (op == 2) {
                cin >> p >> s2;
                s.insert(p, s2);
            }
            if (op == 3) {
                cin >> l >> r;
                reverse(s.begin() + l, s.begin() + r + 1);
            }
            cout << s << '\n';
        }
    }
}