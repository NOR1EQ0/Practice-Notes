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

int asciitable[256];

int main()
{
    fastio;
    // start
    string s;
    s.reserve((int)1e3 + 5);
    int score = 0;
    cin >> s;
    for (int i = 0; i < 26; ++i)
    {
        cin >> asciitable['a' + i];
    }
    unordered_map<char, int> s1;
    for (auto i: s) {
        s1[i]++;
        score += asciitable[static_cast<int>(i)];
    }
    for (int i = 0; i < 25; ++i)
    {
        cout << s1['a'+i] << ' ';
    }
    cout << s1['z'] << '\n' << score << '\n';
    return 0;
}