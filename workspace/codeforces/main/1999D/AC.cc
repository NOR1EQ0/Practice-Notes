#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    string s, t;
    while (T--) {
        cin >> s >> t;
        auto slen = s.length(),
             tlen = t.length();
        ll idx = 0;
        for (ll i = 0; i < slen; i++) {
            if (s[i] == '?') {
                if (idx < tlen) s[i] = t[idx++];
                else s[i] = 'a';
            } else if (s[i] == t[idx]) ++idx;
        }
        if (idx >= t.length()) cout << "YES\n" << s << '\n';
        else cout << "NO\n";
    }
}