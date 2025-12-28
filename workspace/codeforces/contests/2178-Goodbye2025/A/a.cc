#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    string s;
    s.reserve(200);
    while (t--) {
        cin >> s;
        auto res = s.find("YY") != string::npos;
        auto res1 = s.find("YNY") != string::npos;
        cout << (res | res1 ? "NO\n" : "YES\n");
    }
}