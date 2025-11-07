#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<int> v;
    v.reserve(n);
    unordered_map<int, int> s(n);
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if (s[tmp]) {
            while (!v.empty()) {
                auto cp = v.back();
                v.pop_back();
                s[cp]--;
                if (cp == tmp) break;
            }
        } else {
            v.emplace_back(tmp);
            s[tmp]++;
        }
    }

    cout << v.size() << '\n';
}