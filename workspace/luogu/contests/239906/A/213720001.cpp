#include <bits/stdc++.h>

using namespace std;
int a[10], b[10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    int time = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        time += min(a[i], b[i]);
    }
    cout << time << '\n';
    return 0;
}