#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin.ignore(PTRDIFF_MAX, '\n');
    ll tmp;
    ll n2{}, n3{}, n5{};
    while (cin >> tmp) {
        while (tmp % 2 == 0) {
            tmp /= 2;
            n2++;
        }
        while (tmp % 3 == 0) {
            tmp /= 3;
            n3++;
        }
        while (tmp % 5 == 0) {
            tmp /= 5;
            n5++;
        }
    }

    cout << min({n2,n3,n5}) << '\n';
}