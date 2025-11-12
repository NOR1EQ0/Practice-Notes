#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    auto _m = max(n, m);
    string s1;
    s1.reserve(_m);
    string s2;
    s2.reserve(_m);
    cin >> s1 >> s2;
    auto firstmis = mismatch(s1.begin(), s1.end(), s2.begin()).first - s1.begin();
    // auto& lstr = s1.size() > s2.size() ? s1 : s2;
    // auto& sstr = s1.size() > s2.size() ? s2 : s1;
    size_t cnt{};
    while (equal(s1.begin() + firstmis, s1.end(), s2.begin() + firstmis, s2.end())) {
    }
    cout << cnt << '\n';
}