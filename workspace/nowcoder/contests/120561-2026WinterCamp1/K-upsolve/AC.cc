#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n==1||n==3) {
            cout << "YES\n";
            if (n==1) cout << "1\n";
            else cout << "1 2 3\n";
        } else {
            cout << "NO\n";
        }
    }
}