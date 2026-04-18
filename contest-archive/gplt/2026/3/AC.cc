#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr auto exceed = "jiu ting tu ran de...\n"sv;
constexpr auto nonposi = "hai sheng ma?\n"sv;
constexpr auto normal = "nin tai cong ming le!\n"sv;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll a, b;
    cin >> a >> b;
    constexpr ll years = 250;
    cout << b - a << '\n';
    if (b - a > years) {
        cout << exceed;
    } else if (b - a <= 0) {
        cout << nonposi;
    } else {
        cout << normal;
    }
}