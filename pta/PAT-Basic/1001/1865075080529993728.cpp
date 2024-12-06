#pragma GCC optimize(2)
#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, step = 0;
    cin >> n;
    while (n != 1) {
        if (n % 2) {
            n = (3 * n + 1) / 2;
        } else {
            n /= 2;
        }
        ++step;
    }
    cout << step << '\n';
    return 0;
}