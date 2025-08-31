#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, x;cin >> n >> x;
        bool pass = true;
        bool press = false;
        int ptr;
        for (ptr = 0; ptr < n; ++ptr) {
            int in; cin >> in;
            if (in == 1) {
                if (x > 0) {
                    press = true;
                } else {
                    pass = false; ptr++; break;
                }
            }
            if (press and x != 0) x--;
        }
        for (;ptr < n; ++ptr) {
            int in; cin >> in;
        }
        cout << (pass ? "YES": "NO") << '\n';
    }
    return 0;
}