#include <bits/stdc++.h>

using namespace std;

bool is_exist_node(list<pair<int, int>>& l, pair<int, int>* ptr) {
    for (auto& i : l) {
        if (&i == ptr) {
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        list<pair<int, int>> l;
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            l.push_back({tmp, tmp});
        }
        size_t cnt = 0;

        auto lmax = max_element(l.begin(), l.end());

        unordered_set<pair<int, int>*> ptrset;

        while (1) {
            auto pre = lmax == l.begin() ? l.end() : prev(lmax);
            auto nxt = lmax == prev(l.end()) ? l.end() : next(lmax);
            int r1 = INT_MAX, r2 = INT_MAX;

            auto preexist = pre != l.end(), nxtexist = nxt != l.end();

            if (preexist) {
                r1 = pre->second;
            }
            if (nxtexist) {
                r2 = nxt->second;
            }
            bool breakflag{};
            if (preexist && nxtexist) {
                if (r1 > r2) {
                    lmax->first = r1;
                    l.erase(pre);
                } else {
                    lmax->first = r2;
                    l.erase(nxt);
                }
            } else {
                if (preexist && lmax->first > r1) {
                    lmax->first = r1;
                    l.erase(pre);
                } else if (nxtexist && lmax->first > r2) {
                    lmax->first = r2;
                    l.erase(nxt);
                } else {
                    ptrset.emplace(&*lmax);
                    breakflag = 1;
                }
            }
            if (breakflag) break;
            else cnt++;
        }
    }
}