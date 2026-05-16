#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned ll;

ll grid[5001][5001];

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0), cin.tie(0);
#endif

    ll n, m;
    cin >> n >> m;
    ll square{n * m}, rectangle{};
    auto [mn, mx] = minmax_element(n, m);
    // square count
    for (ll i = 2; i <= mn; i++) {
        ll mn_cnt = mn / i;
        ll mx_cnt = mx / i;
        square += (mn_cnt * mx_cnt);
        // for (ll i = 1; i <= )
    }

    cout << square << ' ';

    cout << rectangle << '\n';
}