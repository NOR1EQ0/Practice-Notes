#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string s;
    cin >> s;
    string cp;
    auto slen = s.size();
    cp.reserve(slen);
    for (int i = 0; i < slen; i++) {
        if (!cp.empty() && s[i] == cp.back()) {
            cp.pop_back();
        } else {
            cp.push_back(s[i]);
        }
    }

    cout << (cp.empty() ? "0" : cp) << '\n';
}