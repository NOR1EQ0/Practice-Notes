#include <bits/stdc++.h>

using namespace std;
// min heap
auto find_parent(long pos) -> long {
    return pos > 0 ? (pos - 1) / 2 : LONG_MIN;
};

long find_left(long pos) {
    return pos >= 0 ? pos * 2 + 1 : LONG_MIN;
}

long find_right(long pos) {
    return pos >= 0 ? pos * 2 + 2 : LONG_MIN;
}

void pushup(vector<int>& v, int val) {
    long pos = v.size();
    v.emplace_back(val);
    auto parent = find_parent(pos);
    while (parent != LONG_MIN) {
        if (v[pos] < v[parent]) {
            swap(v[pos], v[parent]);
            pos = parent;
            parent = find_parent(pos);
        }
    }
}

void siftdown(vector<int>& v) {
    long pos{};
    long l = find_left(pos), r = find_right(pos);
    while (l != LONG_MIN && l < v.size() && r != LONG_MIN && r < v.size()) {
        auto lval = l == LONG_MIN ? INT_MIN : v[l],
             rval = r == LONG_MIN ? INT_MIN : v[r],
             posval = v[pos];
        auto rnode = rval > lval;
        if (rnode) {
            swap(v[r], v[pos]);
            pos = r;
            l = find_left(pos), r = find_right(pos);
        } else {
            if (rval != lval) {
                swap(v[l], v[pos]);
                pos = l;
                l = find_left(pos), r = find_right(pos);
            }
        }
    }
}

void popup(vector<int>& v) {
    swap(v.front(), v.back());
    v.pop_back();
    siftdown(v);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<int> v;
    while (n--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            cin >> x;
            pushup(v, x);
        } else if (op == 2) {
            cout << v.front() << '\n';
        } else {
            popup(v);
        }
    }
}