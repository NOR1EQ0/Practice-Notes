#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    auto it = upper_bound(s.begin(), s.end(), '0');
    if (it != s.end()) {
        iter_swap(it, s.begin());
    }
    cout << s;
}