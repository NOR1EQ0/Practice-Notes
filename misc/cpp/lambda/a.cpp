#include <bits/stdc++.h>

using namespace std;

int main() {
    int a = 0;
    int& b = a;
    int&& c = 5;
    vector<int> arr;
    arr.push_back(c);
    a = [b]() -> int {
        return 1;
    }();
    c = 6*a;
    for (auto i : arr) {
        i=1;
    }
    cout << a << endl;
    cout << c << endl;
    cout << arr[0] << endl;
}