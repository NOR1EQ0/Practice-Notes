#include <iostream>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int a, b;
    cin >> a >> b;
    cout << (a * 10 + b) / 19 << endl;
    return 0;
}