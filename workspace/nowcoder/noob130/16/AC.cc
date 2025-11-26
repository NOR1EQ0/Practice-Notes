#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int seconds;
    cin >> seconds;
    auto hr = seconds / 3600;
    auto minute = seconds / 60 - hr * 60;
    auto sec = seconds % 60;
    cout << hr << ' ' << minute << ' ' << sec << '\n';
}