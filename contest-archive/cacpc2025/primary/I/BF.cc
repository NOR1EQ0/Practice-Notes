#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 100000007;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<ll> v(n);
    ll sum{};
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            auto arg1 = v[i], arg2 = v[j];
            auto gcdn = gcd(arg1, arg2) % MOD, lcmn = lcm(arg1, arg2) % MOD;
            sum = (sum + ((gcdn % MOD) * (lcmn % MOD)) % MOD) % MOD;
        }
    }

    cout << sum << '\n';
}