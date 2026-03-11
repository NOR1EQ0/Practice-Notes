#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ay, by;
        cin >> ay >> by;
        for (int i = 1; i < n; i++) {
            int a,b;
            cin >> a >> b;
            if (ay < a) ay = a;
            if (by < a) by = a;
            if (ay > b) ay = b;
            if (by > b) by = b;
        }
        cout << max(ay, by) << '\n';
    }
}