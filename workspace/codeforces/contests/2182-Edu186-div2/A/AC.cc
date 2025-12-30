#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (s.find("2026") != s.npos) {
            cout << "0\n";
        } else if (s.find("2025") != s.npos) {
            cout << "1\n";
        } else {
            cout << "0\n";
        }
    }
}