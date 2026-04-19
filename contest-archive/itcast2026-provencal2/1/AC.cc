#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, x;
        cin >> n;
        ll cnt = n - 1;
        vector<ll> v(n+1);
        for (auto& i: v) {
            cin >> i;
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        auto len = v.size();
        for (ll i = 1; i < len; i++) {
            cnt += abs(v[i-1] - v[i]);
        }
        cout << cnt << '\n';
    }
}