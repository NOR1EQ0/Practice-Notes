#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string s;
    cin >> s;
    int n;
    cin >> n;
    while (n--) {
        int start, end;
        string prestr, poststr;
        cin >> start >> end >> prestr >> poststr;
        string sub = s.substr(start - 1, end - start + 1);
        s.erase(start - 1, end - start + 1);
        size_t pos = 0;
        bool insert = false;
        while (pos != string::npos) {
            pos = s.find(prestr, pos);
            if (pos != string::npos) {
                auto postpos = pos + prestr.length();
                const auto poststr_len = poststr.length();
                bool match = true;
                for (size_t i = 0; i < poststr_len; i++) {
                    if (s[postpos + i] != poststr[i]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    s.insert(pos + prestr.length(), sub);
                    insert = true;
                    break;
                } else {
                    pos += prestr.length();
                }
            }
        }
        if (!insert) {
            s += sub;
        }
    }
    cout << s << '\n';
}