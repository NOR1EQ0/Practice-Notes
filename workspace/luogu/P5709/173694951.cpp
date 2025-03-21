#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, t, s;
    cin >> m >> t >> s;
    if (t == 0)
        cout << 0;
    else {
        cout << (s / t >= m ? 0 : m - s / t - (bool)(s % t));
    }
    return 0;
}