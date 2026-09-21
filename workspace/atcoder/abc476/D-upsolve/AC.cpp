#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using PLL = pair<ll, ll>;
constexpr ll MOD = 998244353;
static inline void solve() {
    ll n, m, k, x, y;
    cin >> n >> m >> k >> x >> y;
    vector<ll> a(n + 1), b(m + 1), bk(m + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    ranges::sort(a), ranges::sort(b);
    for (int i = 1; i <= m; i++) {
        bk[i] = (b[i] / k + (bool)(b[i] % k)) + bk[i - 1];
        b[i] += b[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        a[i] += a[i - 1];
    }

    ll ans = 0;
    for (int i = 0; i <= m; i++) {
        // i: pick i drinks
        ll balance = x + y * k - b[i];
        ll yafter = y - bk[i];
        if (balance < 0 || yafter < 0) break;

        auto it = ranges::upper_bound(a, balance);
        if (it != a.end()) {
            ans = max<ll>(ans, it - a.begin() - 1 + i);
        } else {
            ans = max<ll>(ans, i + n);
        }

        // ll dessert = it - a.begin() - 1;
        // ans = max(ans, dessert + i);
    }
    cout << ans << '\n';

#if 0 

    vector<pair<ll, int>> v(n + m);
    fill(v.begin(), v.begin() + n, pair<ll, int>(0, 1));
    fill(v.begin() + n, v.end(), pair<ll, int>(0, 2));
    for (auto& [i, _] : v) {
        cin >> i;
    }
    ranges::sort(v);
    auto kbalance = k * y;
    auto balance = x + kbalance;

    ll ans = 0;
    // 1 for dessert, 2 for drink
    for (auto&& [price, type] : v) {
        price -= type;
        if (type == 1) {
            if (x >= price) x -= price;
            else {
                auto kconsume = price / k,
                     restcoin = price % k;
                if (x >= restcoin) {
                    if (y - kconsume < 0) {
                        continue;
                    }
                    x -= restcoin;
                } else {
                    kconsume++;
                    if (y - kconsume < 0) {
                        continue;
                    }
                    x += (kconsume * k - price);
                }
                y -= kconsume;
            }
        } else {
            auto kconsume = price / k + (bool)price % k;
            if (y - kconsume < 0) {
                continue;
            } else {
                y -= kconsume;
                x += (kconsume * k - price);
            }
        }
        kbalance = y * k;
        ans++;
    }
    cout << ans << '\n';

    for (auto& i : a) cin >> i;
    for (auto& i : b) cin >> i;
    ranges::sort(a), ranges::sort(b);
    auto kbalance = y * k;
    ll ans = 0;
    for (auto i : b) {
        auto consume = i / k + (bool)i % k;
        if (y >= consume) {
            y -= consume;
            kbalance -= consume * k;
            x += (consume * k - i);
            ans++;
        } else {
            break;
        }
    }
    auto balance = kbalance + x;
    for (auto i : a) {
        balance -= i;
        if (balance < 0) {
            break;
        } else {
            ans++;
        }
    }
    cout << ans << '\n';
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