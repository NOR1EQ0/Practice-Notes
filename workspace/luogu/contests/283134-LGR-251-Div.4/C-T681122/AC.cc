#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios::sync_with_stdio(0);
    cin.tie(0);
    using ul = size_t;
    std::string s;
    cin>>s;
    const auto len = s.size();
    for (ul i = 1; i < len; i++) {
        if (s[i]!='0') {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
}