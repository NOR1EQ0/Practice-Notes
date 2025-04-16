#include <bits/stdc++.h>

using namespace std;
#define v 'V'
#define k 'K'

// /article/tfwgkupd -> replace VK to X

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int len; cin >> len;
    int vks = 0;
    string str; cin >> str;
    bool modify = false;
    for (int i = 0; i < len; ++i) {
        auto ret = str.find("VK", i);
        if (ret != str.npos) {
            str.replace(ret, 2, "X");
            vks++;
        }
    }
    auto ret = str.find("VV");
    if (ret != str.npos)
        vks++;
    else {
        ret = str.find("KK");
        if (ret != str.npos) vks++;
    }
    cout << vks << '\n';
    return 0;
}