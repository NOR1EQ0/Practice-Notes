#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr auto MAXN = (int)1e5;

vector<int> primes;
bool is_composite[(int)1e5 + 5];

void sieve() {
    for (int i = 2; i <= MAXN; i++) {
        if (!is_composite[i]) {
            primes.push_back(i);
        } else {
            continue;
        }
        for (auto p : primes) {
            if (1ll * p * i > MAXN) return;
            if (i % p == 0) {
                is_composite[1ll * p * i] = true;
                break;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    sieve();
    // Check sieves
    for (auto i : primes) {
        cout << i << ' ';
    }
    return 0;

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<int>());
    auto maxn = v.front();
    ll t = maxn;
}