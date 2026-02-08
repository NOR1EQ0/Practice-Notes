#include <bits/stdc++.h>

using namespace std;

int main() {
    int x;
    cin >> x;
    bool flag = false;
    for (int i = 1; i <= x; i++) {
        if (i * (i + 1) == x) {
            flag = true;
            break;
        }
    }
    cout << (flag ? "YES\n" : "NO\n");
}