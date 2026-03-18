#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        int n = a.size();
        for (int i = 1; i < n; i+=2) {
            a[i] = b[i];
        }
        cout << a << '\n';
    }
}