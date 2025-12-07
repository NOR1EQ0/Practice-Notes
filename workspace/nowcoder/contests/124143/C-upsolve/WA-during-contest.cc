#include <bits/stdc++.h>

using namespace std;
constexpr auto MOD = 998244353;

size_t factorial(int n) {
    size_t res = 1;
    for (int i = 2; i <= n; ++i) {
        res = (res * i) % MOD;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string s;
    int n;
    cin >> n >> s;
    unordered_map<char, size_t> umap;
    for (auto i : s) {
        umap[i]++;
    }
    // size_t sol = factorial(umap.size());
    size_t sol = umap.size() * (1 + umap.size()) / 2;
    for (auto i: umap) {
        sol = ((sol % MOD) * i.second) % MOD;
    }
    cout << sol << '\n';
}