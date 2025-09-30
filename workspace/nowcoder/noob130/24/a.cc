#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cout << [n]() {
        if (n%2) return 3*n+1;
        return n/2;
    }() << '\n';
    return 0;
}