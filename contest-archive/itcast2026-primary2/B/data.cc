#include <bits/stdc++.h>

using namespace std;
// constexpr auto MAXN = (int)1e9;
constexpr auto MAXN = (int)50;

int main() {
    // ios::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "wb", stdout);
    random_device rd;
    
    mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
    #define nextint ((int)(mt()))

    int n = abs(nextint) % 20;
    int k = abs(nextint) % n;
    cout << n << ' ' << k << '\n';
    for (int i = 0; i < n; i++) {
        cout << abs(nextint) % MAXN << " \n"[i == n - 1];
    }
    for (int i = 0; i < n; i++) {
        cout << abs(nextint) % MAXN << " \n"[i == n - 1];
    }
}