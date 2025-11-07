#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define noans "-1\n"

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    vector<ll> vodd;
    vector<ll> veven;
    vodd.reserve(2e4);
    veven.reserve(2e4);
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            ll tmp;
            cin >> tmp;
            tmp % 2 ? vodd.emplace_back(tmp) : veven.emplace_back(tmp);
        }

        auto is_odd_bigger = vodd.size() > veven.size();
        auto& vb = is_odd_bigger ? veven : vodd;
        auto& vs = is_odd_bigger ? vodd : veven;
        const auto vblen = vb.size(), vslen = vs.size();

        for (int i = 0; i < vslen; i++){
            for (int j = i + 1; j < vslen; j++) {
                if (vs[j] % vs[i] % 2) continue;
                else {
                    cout << vs[i] << ' ' << vs[j] << '\n';
                    goto clear;
                }
            }
        }

        for (int i = 0; i < vblen; i++){
            for (int j = i + 1; j < vblen; j++) {
                if (vb[j] % vb[i] % 2) continue;
                else {
                    cout << vb[i] << ' ' << vb[j] << '\n';
                    goto clear;
                }
            }
        }

        cout << noans;

    clear:
        vodd.clear();
        veven.clear();
    }
}