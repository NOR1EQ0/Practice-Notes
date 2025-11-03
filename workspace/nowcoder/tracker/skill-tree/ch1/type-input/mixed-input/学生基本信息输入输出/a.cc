#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    int i;
    double a, b, c;
    char c;
    cin >> i >> a >> b >> c;
    cout << "The each subject score of No. " << i << " is " << fixed << setprecision(6) << a << ", " << b << ", " << c << ".\n";
}