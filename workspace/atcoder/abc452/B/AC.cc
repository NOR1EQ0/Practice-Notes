#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int h, w;
    cin >> h >> w;
    string border;
    for (int i = 0; i < w; i++) {
        border += '#';
    }
    border += '\n';

    string middle = "#";
    for (int i = 1; i < w - 1; i++) {
        middle += '.';
    }
    middle += "#\n";
    cout << border;
    for (int i = 1; i < h - 1; i++) {
        cout << middle;
    }
    cout << border;
}