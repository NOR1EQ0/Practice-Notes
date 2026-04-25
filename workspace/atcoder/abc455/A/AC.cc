#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    if (a != b && b == c) {
        cout << "Yes\n"sv;
    } else {
        cout << "No\n"sv;
    }
}