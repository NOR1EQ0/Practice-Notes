#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;
using ll = long long;

void quicksort(vector<ull>& v, ll l, ll r) {
    ll i = l, j = r;
    ull flag = v[(l + r) / 2];
    do {
        while (v[i] < flag) i++;
        while (v[j] > flag) j--;
        if (i <= j) {
            swap(v[i], v[j]);
            i++, j--;
        }
    } while (i <= j);
    if (l < j) quicksort(v, l, j);
    if (i < r) quicksort(v, i, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<ull> v;
    ull n;
    cin >> n;
    v.reserve(n);
    while (n--) {
        ull tmp;
        cin >> tmp;
        v.emplace_back(tmp);
    }
    cout << "emplace done" << endl;
    quicksort(v, 0, v.size() - 1);
    for (const auto i : v) {
        cout << i << ' ';
    }
}