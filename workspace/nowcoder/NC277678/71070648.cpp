#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    int x, y, n;
    std::cin >> x >> y >> n;
    if (n < x + y) {
        std::cout << "NO" << std::endl;
    } else {
        std::cout << "YES" << std::endl;
    }
    return 0;
}