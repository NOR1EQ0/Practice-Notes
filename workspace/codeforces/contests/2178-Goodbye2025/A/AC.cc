#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef FASTIO
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    int t;
    cin >> t;
    string s;
    s.reserve(200);
    while (t--) {
        cin >> s;
        size_t nn = 0, yn = 0, ny = 0;
        while (nn != string::npos || yn != string::npos || ny != string::npos) {
            nn = s.find("NN");
            if (nn != string::npos) {
                s.erase(nn,1);
                continue;
            }

            yn = s.find("YN");
            if (yn != string::npos) {
                s.erase(yn,1);
                s[yn] = 'Y';
                continue;
            }

            ny = s.find("NY");
            if (ny != string::npos) {
                s.erase(ny,1);
                continue;
            }
        }

        cout << (s.find("YY") != string::npos
                     ? "NO\n"
                     : "YES\n");
    }
}