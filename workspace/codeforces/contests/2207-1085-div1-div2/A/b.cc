#include <bits/stdc++.h>

using namespace std;
using PII = pair<size_t, size_t>;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t, n;
    cin >> t;
    string s;
    string ls;
    const string pa1 = "101",
                 pa2 = "111";

    while (t--) {
        cin >> n >> s;
        // find contiguous zero (>=2)
        int ans = s.front() == '1';
        s.erase(s.begin(), find(s.begin(), s.end(), '1'));
        auto it = s.find("00", 0);
        vector<PII> v;
        while (1) {
            it = s.find("00", it);
            if (it == string::npos) break;
            auto zero_end = s.find('1', it);
            if (zero_end != string::npos) {
                v.emplace_back(it, zero_end);
                it = zero_end;
            } else {
                v.emplace_back(it, s.size());
                break;
            }
        }
        for (auto [a,b]: v) {
            cout << a << ' ' << b << '\n';
        }
    }
}