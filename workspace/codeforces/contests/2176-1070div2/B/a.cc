#include <bits/stdc++.h>

using namespace std;
constexpr auto npos = string::npos;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    string s;
    while (t--) {
        int n;
        cin >> n;
        s.reserve(n);
        cin >> s;
        auto _1stone = s.find('1');
        auto _lastone = s.find_last_of('1');
        ll tmp{};
        if (_1stone != npos) tmp += _1stone;
        if (_lastone != npos) tmp += (s.size() - 1 - _lastone);
        ll maxd = 0;
        for (auto i = _1stone; i < _lastone; i++) {
            ll thisd = 0;
            auto j = i + 1;
            for (; j < _lastone; j++) {
                if (s[j] == '1') {
                    break;
                }
            }
            thisd += (j - i - 1);
            i = j;
            maxd = max(maxd, thisd);
        }

        cout << max(tmp, maxd) << '\n';
    }
}