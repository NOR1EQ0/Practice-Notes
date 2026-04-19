#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<ll> va(n), vb(n);
        for (auto &i : va)
            cin >> i;
        for (auto &i : vb)
            cin >> i;
        ll stress{};
        ll knowledge{};
        for (ll i = 0; i < n; i++) {
            if (vb[i] + stress > m) {
                stress = max(ll{}, stress - vb[i]);
            } else {
                stress += vb[i];
                knowledge += va[i];
            }
        }
        cout << knowledge << '\n';
    }
}