#include <bits/stdc++.h>

using namespace std;

template<typename T>
bool checkInt(const T&) {
    if constexpr (is_integral<T>::value) {
        return true;
    } else {
        return false;
    }
}

int main() {
    cout << checkInt(2);
    cout << checkInt(8u);
    cout << checkInt(2.3f);
    return 0;
}