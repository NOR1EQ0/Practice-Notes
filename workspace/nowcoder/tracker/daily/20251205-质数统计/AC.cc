#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e6;

vector<int> primes;
bool is_composite[(int)1e6 + 5];
long prefixsum[MAXN + 5];

void sieve() {
    for (int i = 2; i <= MAXN; i++) {
        if (!is_composite[i]) primes.emplace_back(i);
        for (int p : primes) {
            if (1ll * p * i > MAXN) break;
            is_composite[p * i] = 1;
            if (i % p == 0) break;
        }
    }
    for (int i = 2; i <= MAXN; i++) {
        prefixsum[i] = prefixsum[i - 1] + !(is_composite[i]);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    sieve();
    int n;
    cin >> n;
    while (n--) {
        int l, r;
        cin >> l >> r;
        cout << prefixsum[r] - prefixsum[l - 1] << '\n';
    }
}