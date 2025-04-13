#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a, b, c;
    int n;
    cin >> n;
    while (n--) {
        cin >> a >> b >> c;
        cout << *a.begin() << *b.begin() << *c.begin() << '\n';
    }
    return 0;
}