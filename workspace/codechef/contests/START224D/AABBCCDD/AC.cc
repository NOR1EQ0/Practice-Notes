#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    string s;
    while (t--) {
        int appeartable[26]{};
        int n;
        cin >> n >> s;
        for (char bitand c : s) {
            c = tolower(c);
            appeartable[c - 'a']++;
        }
        auto maxp = max_element(appeartable, appeartable + 26);
        int ans = *maxp;
        *maxp = 0;
        ans += *max_element(appeartable, appeartable + 26);
        cout << ans << '\n';
    }
}