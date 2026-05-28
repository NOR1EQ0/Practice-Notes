#include <bits/stdc++.h>
#define mypow(x) ((x) * (x))
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;
static inline void solve() {
    struct seg {
        char c;
        ll len;
    };
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<seg> segments;
    for (int i = 0; i < n;) {
        int j = i;
        while (j < n && s[j] == s[i]) j++;
        auto len = j - i;
        segments.emplace_back(s[i], len);
        i = j;
    }
    // for (auto [c,len]: segments) {
    //     cout << c << ' ' << len << '\n';
    // }
    int seg_cnt = segments.size();

    ll base{};
    for (auto& [c, len] : segments) {
        base += len * len;
    }

    ll maxdiff = LLONG_MIN;

    for (int i = 0; i < seg_cnt - 1; i++) {
        auto &L = segments[i], &R = segments[i + 1];

        ll old_region = mypow(L.len) + mypow(R.len);
        bool lneigh = i - 1 >= 0,
             rneigh = i + 2 < seg_cnt;
        if (lneigh) old_region += mypow(segments[i - 1].len);
        if (rneigh) old_region += mypow(segments[i + 2].len);
        ll new_region = 0;

        if (L.len == 1 && R.len == 1) {
            // Left part
            if (lneigh) {
                if (segments[i - 1].c == R.c)
                    new_region += mypow(segments[i - 1].len + 1); // [l = R, len(l) + 1]
                else
                    new_region += mypow(segments[i - 1].len) + 1; // [l, len(l)] [R, 1]
            } else {
                new_region += 1; // [R, 1]
            }
            // Right part
            if (rneigh) {
                if (segments[i + 2].c == L.c)
                    new_region += mypow(segments[i + 2].len + 1); // [r = L, len(r) + 1]
                else
                    new_region += mypow(segments[i + 2].len) + 1; // [L, 1] [r, len(r)]
            } else {
                new_region += 1; // [L, 1]
            }
        } else if (L.len == 1 && R.len >= 2) { // [L, 1] will be at the front of the right part
            // Left part
            if (lneigh) {
                if (segments[i - 1].c == R.c)
                    new_region += mypow(segments[i - 1].len + 1); // [l = R, len(l) + 1]
                else
                    new_region += mypow(segments[i - 1].len) + 1; // [l, len(l)] [R, 1]
            } else {
                new_region += 1; // [R, 1]
            }
            // Right part
            new_region += 1;                                      // [L, 1] must be exist
            new_region += mypow(segments[i + 1].len - 1);         // [R, len(R) - 1]
            if (rneigh) new_region += mypow(segments[i + 2].len); // [r, len(r)], simple copy if exist

        } else if (L.len >= 2 && R.len == 1) { // [R, 1] will be at the back of the left part
            // Left part
            if (lneigh) new_region += mypow(segments[i - 1].len); // [l, len(l)], simple copy if exist
            new_region += mypow(segments[i].len - 1);             // [L, len(L) - 1]
            new_region += 1;                                      // [R, 1]

            // Right part
            if (rneigh) {
                if (segments[i + 2].c == L.c)
                    new_region += mypow(segments[i + 2].len + 1); // [r = L, len(r) + 1]
                else
                    new_region += mypow(segments[i + 2].len) + 1; // [L, 1] [r, len(r)]
            } else {
                new_region += 1; // [L, 1]
            }

        } else /* if (L.len >= 2 && R.len >= 2) */ {
            // copy neighbors
            if (lneigh) new_region += mypow(segments[i - 1].len);
            if (rneigh) new_region += mypow(segments[i + 2].len);

            // Singleton after swap
            new_region += 2;

            // Left part
            new_region += mypow(segments[i].len - 1);
            // Right part
            new_region += mypow(segments[i + 1].len - 1);
        }

        maxdiff = max(maxdiff, new_region - old_region);
    }

    cout << base + maxdiff << '\n';

#if 0
    for (int i = 0; i < seg_cnt - 1; i++) {
        // swap(seg1,seg2)

        // if both seg's len equal to 1, consider diff as 1
        if (segments[i].len == 1 && segments[i + 1].len == 1) {
            maxdiff = max(maxdiff, (ll)1);
        }

        // calculate original
        ll original_sum = mypow(segments[i].len) + mypow(segments[i + 1].len);

        // ll arr[2] = {segments[i].len - 1, segments[i + 1].len - 1};
        //         ll arr[2] = {mypow(segments[i].len) - mypow(segments[i].len - 1),
        //                      mypow(segments[i + 1].len) - mypow(segments[i + 1].len - 1)};
        // ll diff = segments[i].len == 1 || segments[i+1].len == 1;
        ll new_sum = mypow(segments[i].len - 1) + mypow(segments[i + 1].len);
        if (i != 0) {
        }

        // maxdiff = max(maxdiff, diff);
    }
#endif
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