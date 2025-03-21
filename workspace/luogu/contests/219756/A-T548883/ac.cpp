#include <iostream>

using namespace std;
int main() {
    int zero = 2012, in;
    cin >> in;
    if (in < zero + 7 || in == zero + 10) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }
    return 0;
}