#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    char c;
    int a;
    double d;
    cin >> c >> a >> d;
    cout << c << ' '
         << a << ' '
         << fixed << setprecision(10) << d << '\n';
}