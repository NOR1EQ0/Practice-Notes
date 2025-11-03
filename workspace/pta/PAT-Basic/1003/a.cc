#include <bits/stdc++.h>

using namespace std;

bool findpat(char c) {
    return (c == 'P' || c == 'A' || c == 'T');
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    string s;
    s.reserve(120);
    while (n--) {
        cin >> s;
        for (auto i : s) {
            if (!findpat) {
                cout << "NO\n";
                goto ed;
            }

        }
    ed:
        0;
    }
}