#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        int n, k;
        cin >> n >> k >> s;
        auto slen = s.size();
        long forcewake{};
        for (size_t i = 0; i < slen; i++) {
            if (s[i] == '1') {
                forcewake = k;
            } else {
                k--;
            }

            if (k) {
                
            }
        }
    }
}