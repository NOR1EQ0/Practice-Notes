#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll arr[3];
    for (auto& i : arr) cin >> i;
    sort(arr, arr + 3);
    cout
        << arr[0] << "->"
        << arr[1] << "->"
        << arr[2] << '\n';
}