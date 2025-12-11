#include <bits/stdc++.h>

using namespace std;
// #define FILE
int main() {
#ifdef FILE
    freopen("./input.txt", "rb", stdin);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int m, n;
    cin >> m >> n;
    vector<int> v(m);
    cin >> v[0];
    size_t cnt = 1;
    size_t misscnt = 1;
    int head = 0, tail = 0;
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        bool hit = false;

        for (int j = head; j <= (tail < head ? m - 1 : tail) && !hit; j++) {
            if (v[j] == x) {
                hit = true;
            }
        }

        for (int j = tail; j < head && !hit; j++) {
            if (v[j] == x) {
                hit = true;
            }
        }

        if (!hit) {
            misscnt++;
            if (cnt < m) {
                cnt++;
                tail = (tail + 1) % m;
            } else {
                v[head] = 0;
                head = (head + 1) % m;
                tail = (tail + 1) % m;
            }
            v[tail] = x;
        }
    }
    cout << misscnt << '\n';
#ifdef FILE
    freopen("./output.txt", "rb", stdin);
    {
        size_t out;
        cin >> out;
        cout.flush();
        assert(out == misscnt);
    }
#endif
}