#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

ll n, k;
vector<ll> v;

void search_nth(ll l, ll r) {
    if (l > r) return;
    auto i = l, j = r;
    while (i < j) {
        while (i < j and v[j] >= v[l]) j--;
        while (i < j and v[i] <= v[l]) i++;
        swap(v[i], v[j]);
    }
    swap(v[i], v[l]);
    search_nth(l, i);
    search_nth(j, r);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    v.reserve(n);
    for (ll i = 0; i < n; i++) {
        ll tmp;
        cin >> tmp;
        v.emplace_back(tmp);
    }
}