#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;
static inline void solve() {
    ll h, w, n, q;
    cin >> h >> w >> n >> q;
    map<ll, ll> rowcnt, colcnt;
    rowcnt[0]=0,colcnt[0]=0;
    while (n--) {
        ll x, y;
        cin >> x >> y;
        rowcnt[x]++, colcnt[y]++;
    }
    {
        auto rowprev = rowcnt.begin(), rowit = next(rowcnt.begin()),
             colprev = colcnt.begin(), colit = next(colcnt.begin());
        for (; rowit != rowcnt.end(); rowit++) {
            rowit->second += rowprev->second;
            rowprev = rowit;
        }
        for (; colit != colcnt.end(); colit++) {
            colit->second += colprev->second;
            colprev = colit;
        }
    }

    while (q--) {
        ll op;
        cin >> op;
        if (op == 1) {
            // row
            ll u, d;
            cin >> u >> d;
            u--;
            auto higher = rowcnt.lower_bound(d), lower = rowcnt.lower_bound(u);
            assert(higher != rowcnt.end());
            assert(lower != rowcnt.end());
        } else {
            // col
            ll l, r;
        }
    }

    // vector<ll> rowcnt(h + 1), colcnt(w + 1);
    // while (n--) {
    //     ll x, y;
    //     cin >> x >> y;
    //     rowcnt[x]++, colcnt[y]++;
    // }
    // for (int i = 1; i <= h; i++) {
    //     rowcnt[i] += rowcnt[i - 1];
    // }
    // for (int i = 1; i <= w; i++) {
    //     colcnt[i] += colcnt[i - 1];
    // }
    // while (q--) {
    //     ll op;
    //     cin >> op;
    // }
}
int main() {
#if defined(ONLINE_JUDGE) || 1
    ios::sync_with_stdio(0), cin.tie(0);
#elif 10
    freopen("1.in", "rb", stdin);
#endif
    ll t = 1;
    while (t--) {
        solve();
    }
}