#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<array<int, 26>> v(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (auto c:s ){
            v[i][c-'a']++;
        }
    }
    for (int i = 0; i < 26; i++) {
        int cnt=0;
        for (int j = 0; j < n; j++) {
            if (v[j][i]) {
                cnt++;
            }
        }
        if (cnt == n) {
            cout <<  ((char)('a'+i)) << '\n';
            return 0;
        }
    }
}