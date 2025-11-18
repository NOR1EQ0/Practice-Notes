#include <bits/stdc++.h>

using namespace std;
vector<int> primes;
bool is_composite[(int)1e8 + 5];

void sieve(int n) {
    for (int i = 2; i <= n; i++) {
        if (!is_composite[i]) {
            primes.emplace_back(i);
        }
        for (auto p : primes) {
            if (1ll * i * p > n) break;
            is_composite[i * p] = 1;
            if (i % p == 0) break;
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, k;
    cin >> n >> k;
    primes.reserve(n / 2);
    sieve(n);
    while (k--) {
        int tmp;
        cin >> tmp;
        cout << primes[tmp - 1] << '\n';
    }
}