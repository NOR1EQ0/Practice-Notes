#include <bits/stdc++.h>

using namespace std;

void push(vector<int>& v, int val) {
    v.emplace_back(val);
    long pos = v.size() - 1;
    while (pos > 0) {
        auto parent = (pos - 1) / 2;
        if (v[pos] < v[parent]) swap(v[pos], v[parent]);
        else
            break;
        pos = parent;
    }
}

void pop(vector<int>& v) {
    swap(v.front(), v.back());
    v.pop_back();
    long pos = 0, size = v.size();
    while (1) {
        long l = pos * 2 + 1;
        long r = pos * 2 + 2;
        long smallest = pos;

        if (l < size && v[l] < v[smallest])
            smallest = l;
        if (r < size && v[r] < v[smallest])
            smallest = r;

        if (smallest == pos) break;

        swap(v[smallest], v[pos]);
        pos = smallest;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    vector<int> v;
    int n;
    cin >> n;
    while (n--) {
        int op;
        cin >> op;
        if (op == 1) {
            int t;
            cin >> t;
            push(v, t);
        } else if (op == 2) {
            cout << v.front() << '\n';
        } else {
            pop(v);
        }
    }
}