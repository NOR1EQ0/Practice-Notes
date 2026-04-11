#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    string_view sv = s;
    auto pos = sv.find_first_not_of('o');
    if (pos != string::npos) {
        sv.remove_prefix(pos);
        cout << sv;
    }
    cout << '\n';
}