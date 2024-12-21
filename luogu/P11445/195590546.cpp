#include <bits/stdc++.h>
using namespace std;

void build(unordered_map<int, bitset<3>> &map, const int num, const int position) {
    auto ite = map.find(num);
    if (ite != map.end()) {
        ite->second.set(position, true);
    } else {
        pair<int, bitset<3>> element;
        element.first = num;
        element.second.reset()
            .set(position, true);
        map.insert(element);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    unordered_map<int, bitset<3>> map(100);
    int n, a, b, c, in, ans = 0;
    cin >> n >> a;
    while (a--) {
        cin >> in;
        build(map, in, 0);

    }
    cin >> b;
    while (b--) {
        cin >> in;
        build(map, in, 1);
    }
    cin >> c;
    while (c--) {
        cin >> in;
        build(map, in, 2);
    }

    for (auto&& i : map) {
        if (i.second.count() > 1) {
            ans++;
        }
    }

    ans += (n - map.size());
    cout << ans << '\n';
    return 0;
}