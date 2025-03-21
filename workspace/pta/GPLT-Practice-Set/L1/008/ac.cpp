#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b; ) {
        for (int j = 0; j < 4 && i < b; ++j) {
            cout << setw(5) << i++;
        }
        cout << setw(5) << i++ << '\n';
    }
    int n = b - a + 1;
    cout << "Sum = " << (a + b) * n / 2 << '\n';
    return 0;
}