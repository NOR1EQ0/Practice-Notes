#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        uint64_t in, ans = 1;
        cin >> in;
        for (;in > 3;in /= 4) {
            ans *= 2;
        }
        cout << ans << '\n';
    }
    return 0;
}