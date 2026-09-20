#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll MOD = 998244353;
static inline void solve() {
    ll n, m, k, x, y;
    cin >> n >> m >> k >> x >> y;
    vector<ll> a(n), b(m);
    for (auto& i : a) cin >> i;
    for (auto& i : b) cin >> i;
    ranges::sort(a), ranges::sort(b);
    for (int i = 1; i < n; i++) a[i] += a[i - 1];
    for (int i = 1; i < n; i++) b[i] += b[i - 1];
    

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