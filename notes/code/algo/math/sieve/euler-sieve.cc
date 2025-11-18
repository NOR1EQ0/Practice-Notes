#include <bits/stdc++.h>

using namespace std;

vector<int> primes;
bool is_composite[(int)1e8 + 5];

void euler_sieve(int n) {
    for (int i = 2; i <= n; i++) {
        if (is_composite[i]) {
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
    cin.tie(0);
    int n;
    cin >> n;
    cout << "Input number: " << n << "\nPrime list: \n";
    for (auto i: primes) {
        cout << i << ' ';
    }
    cout << "\nDone!\n";
}