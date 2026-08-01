#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    int satisfy{};
    for (int i = 0; i < n; i++) {
        if (s[i] == 'x') {
            if ((i - 1 < 0 || s[i - 1] == 'x') && (i + 1 >= n || s[i + 1] == 'x')) {
                satisfy++;
            }
        }
    }
    cout << satisfy << '\n';
}