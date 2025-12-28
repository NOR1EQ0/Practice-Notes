#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int x,y;
    cin >> x >> y;
    if (x == y) {
        cout << "Draw\n";
    } else {
        cout << (x > y ? "Alice\n" : "Bob\n");
    }
}