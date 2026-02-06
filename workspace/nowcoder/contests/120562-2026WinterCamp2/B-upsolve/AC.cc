#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        map<int, int, greater<>> m;
        for (auto& i : v) cin >> i, m[i]++;

        auto [val, cnt] = *m.begin();

        if (cnt % 2) {
            for (auto i : v) cout << (i == val ? '1' : '0');
        } else {
            for (auto i : v) cout << (i == val ? '0' : '1');
        }
        cout << '\n';
    }
}