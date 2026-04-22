#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    map<int, int, greater<>> m;
    int sum = 0;
    while (n--) {
        int tmp;
        cin >> tmp;
        if (tmp == 4) {
            sum++;
        }
        m[tmp]++;
    }
    if (m.count(3)) {
        sum += m[3];
        if (m.count(1)) {
            m[1] = max(0, m[1] - m[3]);
            if (!m[1]) {
                m.erase(1);
            }
        }
    }
    if (m.count(2)) {
        auto cnt = m[2];
        auto rest = cnt % 2, group = cnt / 2;
        sum += group;
        if (rest) {
            sum += 1;
            if (m.count(1)) {
                m[1] = max(0, m[1] - 2);
                if (!m[1]) {
                    m.erase(1);
                }
            }
        }
    }
    if (m.count(1)) {
        sum += (m[1] / 4 + bool{m[1] % 4});
    }
    cout << sum << '\n';
}