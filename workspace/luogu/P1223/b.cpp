#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    ull total{};
    multimap<int, size_t> m;
    {
        int a;
        cin >> a;
        m.emplace(a, 1);
    }
    for (int i = 2; i <= n; i++) {
        int tmp;
        cin >> tmp;
        m.emplace(tmp, i);
        total += tmp;
    }
    unordered_set<size_t> sorted(n);
    for (auto i = m.begin(); i != m.end(); i++) {
        if (sorted.find(i->first) != sorted.end()) {
            continue;
        }
        auto cnt = m.count(i->first);
        auto is_multiple = cnt != 1;
        if (is_multiple) {
            auto [l, r] = m.equal_range(i->first);
            vector<size_t> tmp;
            tmp.reserve(cnt);
            for (auto it = l; it != r; it++) {
                tmp.emplace_back(it->second);
            }
            sort(tmp.begin(), tmp.end());
            for (auto num : tmp) {
                cout << num << ' ';
            }
            sorted.emplace(i->first);
        } else {
            cout << i->second << ' ';
        }
    }
    cout << total << endl;
    auto average = total / (long double)(n - 1);
    cout << '\n'
         << fixed << setprecision(2) << average << '\n';
}