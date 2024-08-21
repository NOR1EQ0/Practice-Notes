#include <iostream>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int a, b, c;
    cin >> a >> b >> c;
    cout << (a * 20 + b * 30 + c * 50) / 100 << "\n";
    return 0;
}