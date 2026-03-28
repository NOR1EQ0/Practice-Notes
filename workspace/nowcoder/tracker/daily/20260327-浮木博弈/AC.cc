#include <bits/stdc++.h>

using namespace std;

constexpr auto alice = "Alice\n"sv,
               bob = "Bob\n"sv;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto& i : v) cin >> i;
        if (v.front() != 1) {
            cout << alice;
        } else {
            auto it = upper_bound(v.begin(), v.end(), 1);
            if (it == v.end()) {
                cout << (n % 2 ? alice : bob);
            } else {
                auto pdiff = it - v.begin();
                cout << (pdiff % 2 == 0 ? alice : bob);
            }
        }
    }
}