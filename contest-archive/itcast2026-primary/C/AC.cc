#include <bits/stdc++.h>

using namespace std;
using ll = long long;

char str[505];

int popcount(unsigned int c) {
    int cnt = 0;
    for (int i = 0; i < CHAR_BIT * sizeof int(); i++) {
        unsigned int mask = 1;
        mask <<= i;
        if (mask & c) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> str;
        auto len = strlen(str);
        for (int i = 0; i < len; i++) {
            char& c = str[i];
            int p = popcount(i + 1);
            if (p % 2) {
                c = toupper(c);
            }
        }
        cout << str << '\n';
    }
}