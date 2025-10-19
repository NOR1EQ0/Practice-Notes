#include <bits/stdc++.h>

using namespace std;
using u64 = uint64_t;
using i64 = int64_t;

string s;
u64 n, k;

bool cond3(size_t index) {
    i64 l = index - k;
    auto subl = max((i64)0, (i64)(index - k));
    auto subr = (i64)index - 1;
    i64 onepos = s.find('1', subl);
    return onepos > subr ? true : false;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    s.reserve(1024);
    u64 t;
    cin >> t;
    while (t--) {
        cin >> n >> k >> s;
        set<size_t> protect_pos;
        for (auto i = 0; i < n; i++) {
            if (s[i] == '0') continue;
            auto ret = cond3(i);
            if (ret) protect_pos.emplace(i);
        }
        auto size = protect_pos.size();
        cout << size << '\n';
    }
}