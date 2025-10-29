#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template <typename T>
bool is_diff_parity(T a, T b) {
    return (a % 2) ^ (b % 2);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    vector<ll> v;
    while (t--) {
        int n;
        cin >> n;
        v.reserve(n);
        bool haseven{}, hasodd{};
        for (int i = 0; i < n; i++) {
            ll tmp;
            cin >> tmp;
            haseven |= (tmp % 2), hasodd |= !(tmp % 2);
            v.emplace_back(tmp);
        }

        // BOTH FLAG
        if (!(haseven ^ hasodd)) {
            for (int i = 0; i < n - 1;) {
                int minnum_i = i;
                bool findmin = false;
                for (int j = 0; j < n; j++) {
                    auto parity = is_diff_parity(v[i], v[j]);
                    if (parity) {
                        if (v[j] < v[minnum_i]) {
                            minnum_i = j;
                            findmin = true;
                        }
                    }
                }
                if (findmin) {
                    swap(v[i], v[minnum_i]);
                } else {
                    i++;
                }
            }
        }

        for (auto i : v) {
            cout << i << ' ';
        }
        cout.put('\n');

        v.clear();
    }
}