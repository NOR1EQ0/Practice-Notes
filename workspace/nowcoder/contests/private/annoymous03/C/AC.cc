#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr auto aka = "biii\n"sv,
               stop = "stop\n"sv,
               notip = "-\n"sv,
               go = "move\n"sv,
               midori = "dudu\n"sv;

enum LIGHT : int {
    RED,
    GREEN,
    YELLOW
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int a, b;
    cin >> a >> b;
    if (a == RED) {
        if (b == 1) {
            cout << notip << stop;
        } else {
            cout << aka << stop;
        }
    } else if (a == YELLOW) {
        cout << notip << stop;
    } else if (a == GREEN) {
        if (b == 1) {
            cout << notip << go;
        } else {
            cout << midori << go;
        }
    }
}