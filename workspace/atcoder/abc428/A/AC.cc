#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    using ul = size_t;
    ul s, a, b, x;
    cin >> s >> a >> b >> x;
    ul circles = x / (a + b), remains = x % (a + b);
    ul circlepath = s * a;
    ul total = circles * circlepath;
    if (remains >= a) {
        total += circlepath;
    } else {
        total += remains * s;
    }
    cout << total << '\n';
}