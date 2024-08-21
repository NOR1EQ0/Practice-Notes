// 莫名其妙过不了，算了做这题纯浪费时间，再见
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int T;
    cin >> T;
    if (T == 1) {
        cout << "I love Luogu!";
    } else if (T == 2) {
        cout << 2 + 4 << " " << 10 - 2 - 4;
    } else if (T == 3) {
        cout << 14 / 4 << "\n" << 14 / 4 * 4 << "\n" << 14 - 14 / 4 * 4;
    } else if (T == 4) {
        cout << setprecision(6) << 500.0 / 3;
    } else if (T == 5) {
        cout << (260 + 220) / (12 + 20);
    } else if (T == 6) {
        cout << sqrt(6 * 6 + 9 * 9);
    } else if (T == 7) {
        cout << "110\n90\n0";
    } else if (T == 8) {
        cout << 10 * 3.141593 << "\n" << 3.141593 * 25 << "\n" << 0.75 * 3.141593 * 125;
    } else if (T == 9) {
        cout << 22;
        // byd小猴
    } else if (T == 10) {
        cout << 9;
    } else if (T == 11) {
        cout << 100 / 3;
    } else if (T == 12) {
        cout << ('M' - 'A' + 1) << '\n' << (char)('A' + 17);
    } else if (T == 13) {
        cout << (int) cbrt(0.75 * 3.141593 * 64 + 0.75 * 3.141593 * 1000);
    } else if (T == 14) {
        cout << 50;
    }
    return 0;
}