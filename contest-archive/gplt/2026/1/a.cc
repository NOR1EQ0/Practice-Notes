#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n, t;
    cin >> n >> t;
    vector<int> stk_l, stk_r;
    stk_l.reserve(n);
    stk_r.reserve(n);
    while (n--) {
        ll chao;
        cin >> chao;
        if (chao > t) {
            stk_l.push_back(chao);
        } else {
            stk_r.push_back(chao);
        }
    }
    ranges::reverse(stk_l);
    do {
        ll sum = reduce(stk_l.begin(), stk_l.end());
        t = sum / stk_l.size();
        erase_if(stk_l, [&](ll val) {
            if (val <= t) {
                stk_r.push_back(t);
                return true;
            } else {
                return false;
            }
        });
    } while (!stk_l.empty());
    for (int i = 0; i < n; i++) {
        cout << stk_r[i];
        if (i != n - 1) cout << ' ';
    }
    cout << '\n';
}