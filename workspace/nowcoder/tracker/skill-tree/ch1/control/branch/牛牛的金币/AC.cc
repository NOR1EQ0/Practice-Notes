#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int x, y, x1, y1;
    cin >> x >> y >> x1 >> y1;
    auto xpos = x1 - x, ypos = y1 - y;
    char o;
    if (xpos < 0) o = 'l';
    if (xpos > 0) o = 'r';
    if (ypos < 0) o = 'd';
    if (ypos > 0) o = 'u';
    cout << o << '\n';
}