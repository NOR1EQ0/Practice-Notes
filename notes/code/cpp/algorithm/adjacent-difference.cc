#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> v = {4, 5, 6, 2, 6, 7654, 3412, 234};
    vector<int> diff(v.size());
    adjacent_difference(v.begin(), v.end(), diff.begin());
    cout << "vector V: ";
    for (auto i : v) {
        cout << i << ' ';
    }
    cout << "\ndiff: ";
    for (auto i : diff) {
        cout << i << ' ';
    }
    cout << '\n';
}