#include <iostream>

using namespace std;
using ll = long long;

ll a[10];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n = 10;
    while (n--) {
        cin >> a[n];
    }
    for (auto i : a) {
        cout << i << ' ';
    }
}   