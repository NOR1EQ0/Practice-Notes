#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    cin >> v[0];
    for (int i = 1; i < n; i++) {
        cin >> v[i];
    }

    while (m--) {
        int op;
        int l, r;
        cin >> op >> l >> r;
        l--, r--;
        if (op == 1) {
            int x;
            cin >> x;
            for (int i = l; i <= r; i++) {
                v[i] = x;
            }
        } else {
            auto [mine, maxe] = minmax_element(v.begin() + l, v.begin() + r);
        }
    }
}