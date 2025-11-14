#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a;
        cin >> a;
        if (a == 3 || a == 6) {
            cout << "koishiYun\n";
        } else {
            cout << "Kato_Shoko\n";
        }
    }
}