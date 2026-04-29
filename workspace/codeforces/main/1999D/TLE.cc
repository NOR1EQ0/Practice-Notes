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
        auto slen = s.size(),
             tlen = t.size();
        // string ans;
        // if (s.find(t) != string::npos) {
        //     replace_if(s.begin(), s.end(), [](char c) { return c == '?'; }, 'a');
        //     cout << "YES\n"
        //          << s << '\n';
        //     continue;
        // }
        ll sidx = 0;
        ll tidx = 0;
        // bool nosuch = false;
        ll match_cnt = 0;
        for (; tidx < tlen; tidx++) {
            ll tmpsidx = sidx;
            for (; tmpsidx < slen; tmpsidx++) {
                if (s[tmpsidx] == '?' || s[tmpsidx] == t[tidx]) {
                    s[tmpsidx] = t[tidx];
                    tmpsidx++;
                    match_cnt++;
                    sidx = tmpsidx;
                    break;
                }
            }
        }
        replace_if(s.begin() + sidx, s.end(), [](char c) { return c == '?'; }, 'a');
        if (match_cnt < tlen) {
            cout << "NO\n";
        } else {
            cout << "YES\n"
                 << s << '\n';
        }
    }
}