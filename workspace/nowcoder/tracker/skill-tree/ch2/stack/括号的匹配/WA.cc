#include <bits/stdc++.h>

using namespace std;

bool match_brace(char l, char r) {
    switch (l) {
        case '<':
            return r == '>';

        case '(':
            return r == ')';

        case '[':
            return r == ']';

        case '{':
            return r == '}';

        default:
            return false;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    string s;
    while (t--) {
        cin >> s;
        vector<char> stk;
        bool res = 0;

        stack<char> bracestk;

        auto satisfy_braceorder = [&](char c) {
            if (bracestk.empty()) return true;
            else {
                auto res = bracestk.top();
                switch (res) {
                    case '{':
                        return c == '{' || c == '[' || c == '(' || c == '<';
                        break;

                    case '[':
                        return c == '[' || c == '(' || c == '<';
                        break;

                    case '(':
                        return c == '(' || c == '<';
                        break;

                    case '<':
                        return c == '<';
                        break;

                    default:
                        return false;
                        break;
                }
            }
        };

        for (auto i : s) {
            bool right_brace = i == '}' || i == ')' || i == ']' || i == '>';
            if (!stk.empty()) {
                if (right_brace) {
                    if (match_brace(stk.back(), i)) {
                        stk.pop_back();
                    } else {
                        break;
                    }
                } else {
                    stk.push_back(i);
                    if (satisfy_braceorder(i)) {
                        bracestk.push(i);
                    } else {
                        break;
                    }
                }
            } else {
                stk.push_back(i);
                if (right_brace) {
                    break;
                }
                bracestk.push(i);
            }
        }

        res = stk.empty();

        cout << (res ? "YES\n" : "NO\n");
    }
}