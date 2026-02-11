#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    int sum = 0;
    for (auto& i : v) cin >> i;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (v[j] <= v[i]) cnt++;
        }
        if (cnt * 10 >= (n - 1) * 8) {
            sum += v[i];
        }
    }
    cout << sum << '\n';
}