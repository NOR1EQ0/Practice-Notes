#include <bits/stdc++.h>

using namespace std;
int n;
int q;
string s, t;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> q;
    while (q--) {
        cin >> n;
        cin >> s >> t;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if (s == t) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout.put('\n');
    }
}