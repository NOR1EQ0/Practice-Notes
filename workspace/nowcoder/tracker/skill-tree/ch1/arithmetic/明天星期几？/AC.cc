#include <iostream>

using namespace std;

int main() {
    char d;
    d = cin.get();
    if (d == '7') cout << "1\n";
    else
        cout << char(d + 1) << '\n';
}