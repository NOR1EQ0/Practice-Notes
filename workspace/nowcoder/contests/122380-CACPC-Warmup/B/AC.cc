#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        n *= 3;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end(), greater());
        size_t fuel{};
        for (int i = 2; i < n; i += 3) {
            fuel += v[i];
        }
        cout << fuel << '\n';
    }
}