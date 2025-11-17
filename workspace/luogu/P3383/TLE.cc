#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool is_prime(ll num) {
    if (num < 2) return false;
    for (ll i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n, q;
    cin >> n >> q;
    vector<ll> v;
    size_t ptr{1};
    v.reserve(n);
    for (ll i = 0; i < q; i++) {
        ll k;
        cin >> k;
        if (k <= v.size()) {
            cout << v[k - 1] << '\n';
            continue;
        }
        k -= v.size();
        while (ptr <= n && k) {
            if (is_prime(ptr)) {
                v.emplace_back(ptr);
                k--;
                if (!k) {
                    cout << ptr << '\n';
                }
            }
            ptr++;
        }
    }
}