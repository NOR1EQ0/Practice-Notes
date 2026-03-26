#include <bits/stdc++.h>

using namespace std;

bool is_rbrack(char c) {
    if (c == '(' || c == '[' || c == '{') return false;
    return true;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string s;
    cin >> s;
    vector<char> v;
    v.reserve(s.size());
    stack<char> stk;

    bool ans = true;

    map<char, char> m;
    m['['] = ']';
    m['('] = ')';
    m['{'] = '}';
    m[']'] = '[';
    m[')'] = '(';
    m['}'] = '{';

    for (char c : s) {
        if (!m.count(c)) continue;

        bool rbrack = is_rbrack(c);
        if (rbrack) {
            if (stk.empty()) {
                ans = false;
                break;
            } else {
                if (m[c] != stk.top()) {
                    ans = false;
                    break;
                } else {
                    stk.pop();
                }
            }
        } else {
            stk.push(c);
        }
    }

    if (ans) {
        ans = !s.empty();
    }

    cout << boolalpha << ans << '\n';
}