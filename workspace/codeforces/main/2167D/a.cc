#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
unordered_set<ull> us;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        unsigned n;
        cin >> n;
        us.reserve(n);
        ull x = ULLONG_MAX;

        unordered_map<ull, ull> um, rum;
        um.reserve(n);
        rum.reserve(n);

        for (unsigned i = 0; i < n; i++) {
            ull tmp;
            cin >> tmp;
            us.emplace(tmp);
        }

        for (auto i : us) {
            auto k1 = um.find(i);
            auto k2 = rum.find(i);
            if (k1 != um.end() and k2 != rum.end()) {
                x = min(k1->second, k2->first);
            } else {
                for (ull j = 2; j < i; j++) {
                    auto match = gcd(i, j) == 1;
                    if (match) {
                        um[i] = j;
                        if (k2 != rum.end()) {
                            um[j] = min(um[j], i);
                        } else {
                            um[j] = i;
                        }
                    }
                }
            }
        }

        // CLEAN
        us.clear();
    }
}