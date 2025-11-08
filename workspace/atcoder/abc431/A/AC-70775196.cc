#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int h, b;
    cin >> h >> b;
    if (h <= b) {
        cout << "0\n";
    } else {
        cout << h - b << '\n';
    }
}