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
        ll n;
        cin >> n;
        vector<int> v(n);
        for (auto &i : v)
            cin >> i;
        //
        sort(v.begin(), v.end());
        ll sum{};
        for (ll i = 0; i < n; i += 2)
        {
            if (i + 2 < n)
            {
                sum += (v[i] * v[i + 2]);
            }
        }
        for (ll i = 1; i < n; i += 2)
        {
            if (i + 2 < n)
            {
                sum += (v[i] * v[i + 2]);
            }
        }
        sum += (v[n - 1] * v[n - 2]);
        cout << sum << '\n';
    }
}