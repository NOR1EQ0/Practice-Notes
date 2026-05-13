#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static inline void solve() {
    string l, r;
    cin >> l >> r;

    if (l == r) {
        ranges::reverse(r);
        cout << stoll(r) << '\n';
        return;
    }

    if (r[0] == '1' && ranges::count(r, '0') == r.size() - 1) {
        cout << string(r.size() - 1, '9') << '\n';
        return;
    }

    if (l.size() < r.size()) {
        l = string(r.size(), '0');
        l.back() = l.front() = '1';
    }

    auto k = ranges::mismatch(l, r).in2;

    if (k == r.end()) {
        ranges::reverse(l);
        cout << l << '\n';
        return;
    } else {
        bool ok = 1;
        for_each(k + 1, r.end(), [&](char c) { ok &= (c == '9'); });
        fill(k + 1, r.end(), '9');
        *k -= !ok;
    }

    ranges::reverse(r);
    cout << r << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}