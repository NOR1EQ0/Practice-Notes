#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    deque<int> h(n);
    deque<int> b(m);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    sort(h.begin(), h.end(), greater());
    sort(b.begin(), b.end(), greater());

    auto bh = n > m;
    int cnt{};

    while (!h.empty() && !b.empty()) {
        auto hi = h.front();
        auto bi = b.front();
        if (hi > bi) {
            while (!h.empty() && hi > bi) {
                h.pop_front();
                hi = h.empty() ? INT_MAX : h.front();
            }
        }
        if (hi <= bi) {
            h.pop_front();
            b.pop_front();
            cnt++;
        }
    }

    cout << (cnt < k ? "No\n" : "Yes\n");
}