#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static inline ll checkPerfectSquare(ll num) {
    auto root = sqrtl(num);
    ll bottom = min((ll)(root - 2), (ll)(0));
    for (ll i = bottom; i <= root + 2; i++) {
        if (i * i == num) {
            return abs(i);
        }
    }
    return -1;
}

static inline void solve() {
    string x;
    cin >> x;
    ll digitsum = 0;

    vector<ll> v;

    for (char c : x) {
        v.push_back(c - '0');
        digitsum += (c - '0');
    }

    // first check perfect square
    auto perfect = checkPerfectSquare(digitsum);
    if (perfect == -1 || perfect > 9) {
        cout << "NO\n";
        return;
    }

    // process until v got only 1 element left
    while (v.size() > 1) {
        vector<ll> tmpv;
        for (int i = 0; i < v.size() - 1; i++) {
            auto num = v[i] + v[i + 1];
            num %= 10;
            tmpv.push_back(num);
        }
        auto non_ldz =
            find_if(tmpv.begin(), tmpv.end(), [](ll &val) { return val != 0; });
        if (non_ldz != tmpv.end()) {
            tmpv.erase(tmpv.begin(), non_ldz);
            v = tmpv;
        } else {
            v = {0};
        }
    }

    if (v[0] == perfect) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}