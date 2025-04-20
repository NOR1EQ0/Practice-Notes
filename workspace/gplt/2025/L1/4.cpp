#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using u64 = uint64_t;
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
#define allit(x)          \
    auto i = (x).begin(); \
    i != (x).end()
#define endl '\n'

int main()
{
    fastio;
    // start
    int n;
    cin >> n;
    bool negative = n < 0;
    if (negative) n=-n;
    ll l = 1;
    while (1)
    {
        if (l << 1 > n)
        {
            break;
        }
        else
            l <<= 1;
    }
    cout << (negative?"-":"") << l << endl;
    return 0;
}