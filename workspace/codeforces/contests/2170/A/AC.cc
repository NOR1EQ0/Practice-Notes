#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        long n;
        cin >> n;
        auto calval = [&](long val) {
            long cnt = val;
            if (val - n >= 1) cnt += (val - n);
            if (val - 1 >= 1 && (val % n != 1)) cnt += (val - 1);
            if (val + 1 <= n * n && val % n) cnt += (val + 1);
            if (val + n <= n * n) cnt += (val + n);
            return cnt;
        };
        long maxval{};
        for (int i = 1; i <= n * n; i++) {
            auto val = calval(i);
            maxval = max(val, maxval);
        }
        cout << maxval << '\n';
    }
}