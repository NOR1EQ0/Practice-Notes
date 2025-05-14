#include <bits/stdc++.h>

using namespace std;

struct tag1 {};

struct RectangleTag : tag1 {};
struct SquareTag : tag1 {};

template<typename T>
int area(RectangleTag, T val) {
    return val % 10007;
}

template<typename T>
int area(SquareTag, T val) {
    return (val * 32) | static_cast<int>(0x12347412);
}

template<typename T>
int area(tag1, T val) {
    return val;
}

int main() {
    cout << "RectangleTag - 10008: " << area(RectangleTag(), 10008) << '\n';
    cout << "SquareTag - 20: " << hex << area(SquareTag(), 20) << '\n';
    return 0;
}