#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int m,n;
    deque<int> q;
    cin >> m >> n;
    long misscnt = 0;
    while (n--) {
        int x;
        cin >> x;
        bool hit = false;

        for (auto i: q) {
            if (i == x) {
                hit = true;
                break;
            }
        }

        if (!hit) {
            misscnt++;
            if (q.size() >= m) {
                q.pop_front();
            }
            q.push_back(x);
        }
    }
    cout << misscnt << '\n';
}