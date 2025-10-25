#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    vector<int> v;
    v.reserve(100);
    int n, m;
    int sum{};
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.emplace_back(tmp);
        sum += tmp;
    }
    for (auto i: v) {
        if (sum - i == m) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
}