#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> primes;
bool is_composite[(int)3e5 + 5];

void euler_sieve(int n) {
    for (int i = 2; i <= n; i++) {
        if (!is_composite[i]) {
            primes.emplace_back(i);
        }
        for (int p : primes) {
            if (1ll * i * p > n) break;
            is_composite[i * p] = true;
            if (i % p == 0) break;
        }
    }
}

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    ll n;
    cin >> n;
    euler_sieve(n);
    ll x = 1ll;
    ll sum{};
    if (!is_composite[n]) {
        cout << n;
    } else {
        for (auto i : primes) {
            ll res, remain;
            while (res = n / i, !(remain = n % i)) {
                n = res;
                sum += i;
            }
            if (n == 1) break;
        }
        cout << sum;
    }
    cout << '\n';
}