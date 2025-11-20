#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    vector<int> a, b;
    a.reserve(2e5 + 5);
    b.reserve(2e5 + 5);
    while (t--) {
        int n;
        cin >> n;
        a.resize(n);
        vector<int> blank_pos;
        cin >> a[0];
        long sum{};
        auto headblank = a[0] == -1; // HEAD
        // if (headblank) blank_pos.emplace_back(0);
        for (int i = 1; i < n; i++) {
            cin >> a[i];
            sum += (a[i] - a[i - 1]);
            // if (a[i] == -1) blank_pos.emplace_back(i);
        }
        auto tailblank = a.back() == -1; // TAIL
        sum = abs(sum);

        if (headblank) {
            cout << 0 << '\n';
            if (tailblank) {
                a.front() = 0;
                a.back() += (sum - 1);
                for (auto i : a) {
                    cout << (i == -1 ? 0 : i) << ' ';
                }
            } else {
                a.front() += sum;
                for (auto i : a) {
                    cout << (i == -1 ? 0 : i) << ' ';
                }
            }
        } else {
            if (tailblank) {
                cout << 0 << '\n';
                for (auto i : a) {
                    cout << (i == -1 ? 0 : i) << ' ';
                }
            } else {
                cout << 0 << '\n';
                a.back() += sum;
                for (auto i : a) {
                    cout << (i == -1 ? 0 : i) << ' ';
                }
            }
        }
        cout << '\n';
    }
}