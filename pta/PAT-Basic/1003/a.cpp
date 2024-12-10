#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#pragma GCC optimize(2)
#define IOS std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
#define pno std::cout << "NO" << '\n';
#define pok std::cout << "YES" << '\n';
using namespace std;

int main() {
    IOS;
    int n;
    char str[101];
    char pat[4] = "PAT", paat[5] = "PAAT";
    cin >> n;
    while (n--) {
        bool patflag = false;
        cin >> str;
        for (char* ch = str; *ch; ++ch) {
            if (patflag && *ch != 'A') {
                patflag = false; break;
            }
            if (*ch != 'P' && *ch != 'A' && *ch != 'T') {
                patflag = false; break;
            }
            if (*ch == 'P' && !patflag) {
                // cout << strncmp(ch, pat, 3) << ' ' << strncmp(ch, paat, 4) << endl;
                if (!strncmp(ch, pat, 3)) {
                    patflag = true; ch += 2;
                } else if (!strncmp(ch, paat, 4)) {
                    patflag = true; ch += 3;
                }
                continue;
            }
        }
        if (patflag) { pok; } else { pno; }
        // cout << flush;
    }
    return 0;
}