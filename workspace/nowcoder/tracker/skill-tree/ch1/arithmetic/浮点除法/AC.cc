#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    double a, b;
    cin >> a >> b;
    cout << fixed << setprecision(3) << a / b << '\n';
}