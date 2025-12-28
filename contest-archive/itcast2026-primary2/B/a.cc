#include <bits/stdc++.h>

using ll = long long;
using namespace std;

struct fruit {
    ll sweet;
    ll sour;
};
int diff(const fruit& l, const fruit& r) {
    auto ldiff = l.sweet - l.sour;
    auto rdiff = r.sweet - r.sour;
    if (ldiff == rdiff) {
        return l.sweet > r.sweet;
    }
    return ldiff > rdiff;
    // if (ldiff == rdiff) {
    //     return 0;
    // }
    // return ldiff > rdiff ? -1 : 1;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, k;
    cin >> n >> k;

    vector<fruit> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].sour;
    }
    for (int i = 0; i < n; i++) {
        cin >> v[i].sweet;
    }

    // for (int i = 0; i < n; i++) {
    //     cout << '{' << v[i].sweet << ',' << v[i].sour << "=>" << v[i].sweet - v[i].sour << '}' << ",\n"[i == n - 1];
    // }
    sort(v.begin(), v.end(), diff);
    // for (int i = 0; i < n; i++) {
    //     cout << '{' << v[i].sweet << ',' << v[i].sour << "=>" << v[i].sweet - v[i].sour << '}' << ",\n"[i == n - 1];
    // }
    ll swtcnt = 0, sourcnt = 0;
    for (int i = 0; i < k; i++) {
        swtcnt += v[i].sweet;
        sourcnt += v[i].sour;
    }   
    cout << sourcnt << ' ' << swtcnt << '\n';
}