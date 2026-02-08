#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> av(n), bv(m);
        ll asum{}, bsum{};
        for (auto& i : av) cin >> i, asum += i;
        for (auto& i : bv) cin >> i, bsum += i;
        int state = 0;
        if (asum < bsum) state = -1;
        else if (asum > bsum)
            state = 1;

        if (!state) {
            cout << "1\n";
            continue;
        }

        sort(av.begin(), av.end(), greater());
        sort(bv.begin(), bv.end(), greater());

        int ans{};
        if (state == -1) {
            for (auto i : bv) {
                bsum -= i;
                ans++;
                if (asum >= bsum) break;
            }
        } else {
            for (auto i : av) {
                asum -= i;
                ans++;
                if (asum <= bsum) break;
            }
        }
        cout << ans << '\n';
    }
}