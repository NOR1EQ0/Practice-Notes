#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        bool find = false;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (v[j] % v[i] % 2 == 0) {
                    cout << v[i] << ' ' << v[j] << '\n';
                    find = 1;
                    goto end;
                }
            }
        }
    end:
        if (!find) {
            cout << "-1\n";
        }
    }
}