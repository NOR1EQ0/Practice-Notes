#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int q;
    cin >> q;
    map<int, int> m;
    while (q--) {
        int op, h;
        cin >> op >> h;
        if (op == 1) {
            m[h]++;
        } else {
            m.erase(m.begin(), m.upper_bound(h));
        }
        int cnt{};
        for (auto [_, i] : m) {
            cnt += i;
        }
        cout << cnt << '\n';
    }
}