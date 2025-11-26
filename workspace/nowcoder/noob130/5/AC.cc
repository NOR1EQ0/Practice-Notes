#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    long a, b;
    double c;
    char d[2];
    string s;
    cin >> a >> b >> c >> d >> s;
    cout << a << '\n'
         << b << '\n'
         << fixed << setprecision(1) << c << '\n'
         << d << '\n'
         << s;
}