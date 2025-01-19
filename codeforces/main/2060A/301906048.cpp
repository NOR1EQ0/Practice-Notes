#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int a[4], b[3], ans = 1;
        for (auto& i : a) cin >> i;
        b[0] = a[0] + a[1];
        b[1] = a[2] - a[1];
        b[2] = a[3] - a[2];
        for (int i = 0; i < 3; ++i) {
            int c = 1;
            int current = b[0];
            for (int j = 0; j < 3; ++j) {
                if (j==i) continue;
                if (b[j] == b[i]) c++;
            }
            if (c>ans) ans=c;
        }
        cout << ans << '\n';
    }
    return 0;
}