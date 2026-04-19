#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    int t;
    cin >> t;
    string p, s;
    while (t--) {
        cin >> p >> s;
        ll pidx{}, sidx{};
        ll pcurcnt{}, scurcnt{};
        auto plen = p.size(), slen = s.size();
        bool legal = true;
        char pcur = p[0], scur = s[0];
        if (pcur != scur) {
            cout << "NO\n"sv;
            continue;
        }
        for (pidx = 0ll; pidx < plen; ) {
            // Keep counting if same
            if (p[pidx] == pcur) {
                pidx++;
                pcurcnt++;
            } else {
                // Count s' sub-str len
                for (; sidx < slen; sidx++) {
                    // Keep counting
                    if (s[sidx] == scur) {
                        scurcnt++;
                    } else {
                        if (scurcnt < pcurcnt || scurcnt > pcurcnt * 2) {
                            legal = false;
                            break;
                        }
                        // Switch scur and reset count 
                        scur = s[sidx];
                        scurcnt = 1;
                        break;
                    }
                }
                // Switch pcur and reset count
                pcur = p[pidx];
                pcurcnt = 1;
            }
            if (!legal) break;
        }
        if (!legal) {
            cout << "NO\n"sv;
        } else {
            // deal with the situation that only hit one drum
            if (!sidx) {
                if (slen < plen || slen > plen * 2) {
                    cout << "NO\n"sv;
                } else {
                    if (count(s.begin(), s.end(), pcur) < slen) {
                        cout << "NO\n"sv;
                    } else {
                        cout << "YES\n"sv;
                    }
                }
                continue;
            }
            if (sidx != slen) {
                cout << "YES\n"sv;
            } else {
                cout << "NO\n"sv;
            }
        }
    }
}