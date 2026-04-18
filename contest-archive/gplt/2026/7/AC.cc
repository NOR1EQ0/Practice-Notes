#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n;
    ll sum{};
    ll mn = LLONG_MAX, mx = LLONG_MIN;
    cin >> n;
    vector<ll> v(n);
    for (auto& i : v) {
        cin >> i;
        mn = min(mn, i);
        mx = max(mx, i);
        sum += i;
    }
    ll ave = sum / n;
    cout << mx << ' ' << mn << ' ' << ave << '\n';
    ll warn = ave * 2;
    bool normal = true;
    vector<int> suspect;
    suspect.reserve(n);
    for (int i = 0; i < n; i++) {
        if (v[i] > warn) {
            normal = false;
            suspect.push_back(i + 1);
        }
    }
    const auto susp_len = suspect.size();
    if (!normal) {
        for (size_t i = 0; i < susp_len; i++) {
            cout << suspect[i];
            if (i != susp_len - 1) {
                cout << ' ';
            }
        }
    } else {
        cout << "Normal"sv;
    }
    cout << '\n';
}