#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool isprime(ll n) {
    if (n == 2) return true;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    ll n;
    cin >> n;
    bool prime = isprime(n);
    vector<int> factors;
    factors.reserve(1e6);
    if (prime || (!prime && n <= 8)) {
        cout << "1\n"sv
             << n << '\n';
    } else {
        // ll rooted = sqrtl(n);
        ll maxlen{}, x;
        for (ll i = 2; i * i <= n; i++) {
            // for (ll i = 2; i <= rooted; i++) {
            if (n % i == 0) {
                ll sx = i;
                ll j = i + 1;
                do {
                    sx *= j;
                    if (n % sx) {
                        break;
                    }
                    j++;
                } while (j * j <= n);
                // for (j = i + 1; j * j <= n; j++) {
                //     // for (j = i + 1; j <= rooted; j++) {
                //     sx *= j;
                //     if (n % sx) {
                //         break;
                //     }
                // }
                if (maxlen < j - i) {
                    maxlen = (j - i);
                    x = i;
                }
            }
        }
        cout << maxlen << '\n';
        for (ll i = x; i < x + maxlen; i++) {
            if (i != x) {
                cout << '*';
            }
            cout << i;
        }
        cout << '\n';
    }
}