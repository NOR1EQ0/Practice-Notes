#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    char s[10];
    cin >> s >> s + 3 >> s + 6;
    for (int i = 0; i <= 4; i++) {
        int rev = 8 - i;
        if (s[i] != s[rev]) {
            cout << "No\n"sv;
            return 0;
        }
    }
    cout << "Yes\n"sv;
}