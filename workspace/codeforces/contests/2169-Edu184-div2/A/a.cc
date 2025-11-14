#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, a;
        cin >> n >> a;
        vector<long> v(n);
        long diff = LONG_MAX;
        size_t index = SIZE_MAX;
        for (int i = 0; i < n; i++) {
            long tmp;
            cin >> tmp;
            v[i] = tmp;
            auto tdiff = abs(tmp - a);
            if (tdiff <= diff) {
                index = i;
                diff = tdiff;
            }
        }
        size_t lpos, rpos;
        if (diff == 0) {
            lpos = index - 1;
            rpos = index + 1;
        } else {
            if (a > v[index]) {
                lpos = index;
                rpos = index + 1;
            } else {
                rpos = index;
                lpos = index - 1;
            }
        }

        
    }
}