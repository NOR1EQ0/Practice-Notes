#include <bits/stdc++.h>

using namespace std;

set<int> primes;
bool is_composite[(int)1e6 + 5];
int sieved_bound = 2;

void sieve(int r) {
    int i = sieved_bound;
    sieved_bound = max(sieved_bound, r);
    for (; i <= sieved_bound; i++) {
        if (!is_composite[i]) primes.emplace(i);
        for (int p : primes) {
            if (1ll * p * i > r) {
                break;
            }
            is_composite[i * p] = true;
            if (i % p == 0) break;
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    while (n--) {
        int l, r;
        cin >> l >> r;
        sieve(r);
        auto loit = lower_bound(primes.begin(), primes.end(), l);
        auto hiit = upper_bound(loit, primes.end(), r);
        auto rangeprime = distance(loit, hiit);
        cout << rangeprime << '\n';
    }
}