#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int i;
        int a;
        bool flag = true;
        cin >> a;
        for (int i = 0; i < 3; i++) {
            int b;
            cin >> b;
            if (b != a) {
                flag = false;
            }
        }
        cout << (flag ? "YES" : "NO") << '\n';
    }
}