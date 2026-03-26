#include <bits/stdc++.h>

using namespace std;

constexpr auto yes = "Good\n"sv,
               no = "Bad\n"sv;

char asciitable[256];

int main() {
    bool upflag = true;
    asciitable['a'] = 'b';
    asciitable['b'] = 'a';
    ios::sync_with_stdio(0), cin.tie(0);
    string s;
    cin >> s;
    bool ans = true;
    vector<char> v;
    for (auto c : s) {
        if (c == 'a') {
            if (upflag)
                v.push_back(c);
        } else {
            upflag = !upflag;
            
        }
    }
}