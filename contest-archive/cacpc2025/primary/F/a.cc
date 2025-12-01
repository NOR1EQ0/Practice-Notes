#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    vector<int> scores;
    scores.reserve(1 << 15);
    int q;
    cin >> q;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            cin >> x;
            scores.push_back(x);
            push_heap(scores.begin(), scores.end());
        } else {
            sort_heap(scores.begin(), scores.end());
            cout << scores[(scores.size() + 1) / 2 - 1] << '\n';
            make_heap(scores.begin(), scores.end());
        }
    }
}