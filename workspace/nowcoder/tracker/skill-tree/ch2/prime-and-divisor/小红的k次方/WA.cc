#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr auto MOD = 998244353;
constexpr auto NUM = 30;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    ll mtp = 1;
    while (n--) {
        ll tmp;
        cin >> tmp;
        mtp = mtp * tmp % MOD;
    }

    ll ans = LLONG_MAX;
    ll k = 0;
    for (ll i = NUM; i <= mtp; i *= i) {
        if (mtp % i) break;

        ans = min(ans, mtp / i);
        k++;
    }

    cout << k << '\n';
}
