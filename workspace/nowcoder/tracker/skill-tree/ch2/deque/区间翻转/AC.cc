#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    deque<int> dq;
    int n, k;
    cin >> n >> k;
    int l = 1, r = 1;
    bool rev = false;
    while (k--) {
        int wndl, wndr;
        cin >> wndl >> wndr;
        while (l < wndl) {
            if (dq.empty()) cout << l << ' ';
            else {
                if (rev) cout << dq.back() << ' ', dq.pop_back();
                else
                    cout << dq.front() << ' ', dq.pop_front();
            }
            l++;
            if (r < l) r++;
        }

        while (r <= wndr) {
            if (rev) dq.push_front(r);
            else
                dq.push_back(r);
            r++;
        }

        rev = !rev;
    }

    if (!dq.empty()) {
        if (!rev) {
            for (auto i : dq) {
                cout << i << ' ';
            }
        } else {
            for (int i = dq.size() - 1; i >= 0; i--) {
                cout << dq[i] << ' ';
            }
        }
    }

    while (r <= n) {
        cout << r << ' ';
        r++;
    }
    cout << '\n';
    return 0;
}