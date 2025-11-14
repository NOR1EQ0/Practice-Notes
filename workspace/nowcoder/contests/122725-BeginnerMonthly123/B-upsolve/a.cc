#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    multimap<int, size_t, greater<>> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        m.emplace(a[i] - b[i], i);
    }
    int t = 1;
    int impact{};
    for (auto i = m.begin(); i != m.end();) {
        auto [lit, rit] = m.equal_range(i->first);
        for (; lit != rit; lit++) {
            auto index = lit->second;
            auto val = a[index] - b[index] * (t - 1);
            impact += val;
            t++;
        }
        i = rit;
    }
    cout << impact << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}