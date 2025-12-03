#include <bits/stdc++.h>

using namespace std;

int asciitable[256];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string s;
    cin >> s;
    for (auto i : s) {
        asciitable[i]++;
    }

    long len = s.size();
    for (auto i : asciitable) {
        len -= (i < 2 ? 0 : i);
    }
    long cnt = (1 + len) * len / 2;
    cout << cnt << '\n';
}