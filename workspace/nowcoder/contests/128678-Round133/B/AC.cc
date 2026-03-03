#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, x;
    cin >> n >> x;
    using ll = long long;
    map<ll, ll> m;
    for (int i = 0; i < n; i++) {
        ll index;
        cin >> index;
        m[index]++;
    }

    auto [idx, cnt] = *max_element(m.begin(), m.end(), [](auto& a, auto& b) {
        return a.second < b.second;
    });

    cout << cnt - m[x] << '\n';
}