#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    char str[15];
    cin >> n;
    long long ans = 0;
    while (n--) {
        cin >> str;
        long long t;
        cin >> t;
        if (str[0] == 'Q' && !str[1]) {
            ans += t;
        }
    }
    cout << ans << '\n';
}