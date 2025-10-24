#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<ll> v = {5, 3, 4, 8, 34, 11};
    for (auto i : v) {
        cout << i << ' ';
    }
    cout << endl;
    sort(v.begin(), v.end(), less());
    for (auto i : v) {
        cout << i << ' ';
    }
    cout << endl;
}