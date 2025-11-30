#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    long cnt{};
    cin >> n;
    while (n--) {
        char s[4];
        cin >> s;
        if (s[1] == '+') {
            cnt++;
        } else {
            cnt--;
        }
    }
    cout << cnt << '\n';
}