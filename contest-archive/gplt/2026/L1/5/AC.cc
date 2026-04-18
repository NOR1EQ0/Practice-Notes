#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    int n;
    cin >> n;
    static constexpr auto none = "NONE\n"sv;
    map<int, bool> m;
    while (n--) {
        int num, rate;
        cin >> num >> rate;
        m[num] |= rate;
    }
    bool nosuch = true;
    for (auto it = m.begin(); it != m.end(); it++) {
        auto [num, rate] = *it;
        if (!rate) {
            nosuch = false;
            cout << num;
            if (next(it) != m.end()) {
                cout << ' ';
            }
        }
    }
    if (nosuch) cout << none;
}