#include <bits/stdc++.h>

using namespace std;

int table[10] = {1, 10, 5, 10, 5, 2, 5, 10, 5, 10};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string s;
    cin >> s;
    int digit = s.back() - '0';
    cout << table[digit] << '\n';
}