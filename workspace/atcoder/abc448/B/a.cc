#include <bits/stdc++.h>

using namespace std;
using PII = pair<int, int>;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    deque<int> c(m);
    vector<PII> v(n);
    for (auto& i : c) cin >> i;
    for (auto& [f, s] : v) cin >> f >> s;

    sort(c.begin(), c.end(), greater());
    sort(v.begin(), v.end(), [](const PII& a, const PII& b) {
        if (b.second > a.second || b.first > a.first) return true;
        return false;
    });

    int ans{};
    for (auto& p : v) {
        if (c.empty()) break;
        int cnt = 0;
        for (int i = 0; i < p.first && !c.empty(); i++) {
            int ct = min(p.second, c.front());
            c.front() -= ct;
            p.second -= ct;
            if (c.front() <= 0) {
                c.pop_front();
            }
            cnt += ct;
        }
        ans += cnt;
    }
    cout << ans << '\n';
}