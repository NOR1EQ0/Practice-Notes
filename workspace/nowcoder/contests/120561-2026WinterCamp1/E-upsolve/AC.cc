#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n;
        n++;
        vector<int> v(n);
        cin >> v[1];
        for (int i = 2; i < n; i++) {
            cin >> v[i];
        }
        cin >> v[0];
        int nmax = v.front() + v.back();
        for (int i = 0; i < n - 1; i++) {
            nmax = max(nmax, v[i] + v[i + 1]);
        }
        cout << nmax << '\n';
    }
}