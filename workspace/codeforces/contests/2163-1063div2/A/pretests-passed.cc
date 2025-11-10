#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        bool winflg{1};
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        for (int i = 1; i < n - 1; i += 2) {
            if (v[i] < v[i + 1]) {
                winflg = 0;
                break;
            }
        }
        cout << "YES\0NO" + !winflg * 4 << '\n';
    }
}