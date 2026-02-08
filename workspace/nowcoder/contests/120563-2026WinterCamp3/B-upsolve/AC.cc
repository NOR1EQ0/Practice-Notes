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
        for (auto& i : v) cin >> i;

        map<int, int> p2val;

        for (auto x : v) {
            if (x == 1) continue;

            int tmp = x;
            for (int i = 2; i * i < tmp; i++) {
                if (tmp % i == 0) {
                    if (p2val.count(i)) {
                        cout << p2val[i] << ' ' << x << '\n';
                        goto ed;
                    }
                    p2val[i] = x;
                    while (tmp % i == 0) tmp /= i;
                }
            }

            if (tmp > 1) {
                if (p2val.count(tmp)) {
                    cout << p2val[tmp] << ' ' << x << '\n';
                    goto ed;
                }
                p2val[tmp] = x;
            }
        }

        cout << "-1\n";

    ed:
        0;
    }
}