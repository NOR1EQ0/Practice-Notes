#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using PLL = pair<ll, ll>;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n, t;
    cin >> n >> t;
    vector<PLL> left;
    vector<ll> right;
    left.reserve(n);
    right.reserve(n);
    for (int i = 1; i <= n; i++) {
        ll chao;
        cin >> chao;
        if (chao > t) {
            right.push_back(i);
        } else {
            left.emplace_back(i, chao);
        }
    }
    ranges::reverse(left);
    while (!left.empty()) {
        auto sum = accumulate(left.begin(), left.end(), ll{}, [](PLL& v1, PLL& v2) { return v1.second + v2.second; });
        t = sum / left.size();
        for (auto& [idx, num] : left) {
            if (num > t) {
                right.push_back(idx);
                num = LLONG_MAX;
            }
        }
        left.erase(remove_if(left.begin(), left.end(),
                             [](PLL& p) {
                                 return p.second == LLONG_MAX;
                             }));
    }
    for (int i = 0; i < n; i++) {
        cout << right[i] << " \n"[i == n - 1];
    }
}