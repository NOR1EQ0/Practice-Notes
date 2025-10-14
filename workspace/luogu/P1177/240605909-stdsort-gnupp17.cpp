#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    typedef uint64_t ull;
    vector<ull> v;
    for (auto i = 0; i < n; ++i) {
        v.push_back((
            {
                ull tmp;
                cin >> tmp;
                tmp;
            }));
    }
    v.reserve((size_t)1e5);
    sort(v.begin(), v.end());
    const auto len = v.size();
    for (size_t i = 0; i < len - 1; i++) {
        cout << v[i] << ' ';
    }
    cout << v.back() << '\n';
}