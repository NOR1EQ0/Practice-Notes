#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    vector<size_t> fib(84);
    fib[1] = fib[2] = 1;
    for (int i = 3; i < 84; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    while (t--) {
        int n;
        cin >> n;
        if (!n) cout << "1\n";
        else {
            cout << fib[n + 3] << '\n';
        }
    }
}