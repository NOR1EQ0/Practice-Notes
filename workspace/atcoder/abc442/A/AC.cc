#include <bits/stdc++.h>

using namespace std;
char s[11];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> s;
    size_t ans = 0;
    for (auto c: s) {
        if (c == 'i' || c == 'j') ans++;
    }
    cout << ans << '\n';
}