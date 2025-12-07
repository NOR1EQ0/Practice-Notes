#include <bits/stdc++.h>

using namespace std;
long long cntarr[26];
constexpr auto MOD = 998244353;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (auto i : s) {
        cntarr[i - 'a']++;
    }

    vector<int> freqs;
    for (auto i : cntarr) {
        if (i > 0) freqs.push_back(i);
    }

    size_t total{};
    auto m = freqs.size();

    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            for (int k = j + 1; k < m; k++) {
                size_t prod = (freqs[i] % MOD) * (freqs[j] % MOD) % MOD;
                prod = prod * (freqs[k] % MOD) % MOD;
                total = (total + prod) % MOD;
            }
        }
    }

    total = total * 6 % MOD;
    cout << total << '\n';
}