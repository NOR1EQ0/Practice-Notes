#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    string s;
    while (t--) {
        int n;
        cin >> n;
        s.reserve(n);
        cin >> s;
        int balance{};
        int del{};
        for (auto i : s) {
            if (i == '(') {
                balance++;
            } else {
                balance--;
            }
            if (balance == -1) {
                del++;
                balance++;;
            }
        }
        del += balance;
        cout << del << '\n';
    }
}