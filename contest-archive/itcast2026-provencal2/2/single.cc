#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<ll> v(n);
    for (auto &i : v)
        cin >> i;
    ll sum = LLONG_MIN;
    while (next_permutation(v.begin(), v.end())) {
        ll cursum{};
        for (ll i = 0; i < v.size() - 1; i++) {
            cursum += (v[i] * v[i+1]);
        }
        cout << cursum << ' ';
        sum = max(cursum, sum);
    }
    cout << "\nMAX: " << sum << '\n';
}