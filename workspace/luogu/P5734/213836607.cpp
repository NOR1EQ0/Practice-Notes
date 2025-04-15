#include <bits/stdc++.h>

using namespace std;
#define endl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int ops; cin >> ops;
    string str; cin >> str; // init
    while (ops--) {
        int op;
        cin >> op;
        switch (op) {
        case 1: {
            string concat;
            cin >> concat;
            str += concat;
            cout << str << endl;
            break;
        }
        case 2:
            int l, r;
            cin >> l >> r;
            str = str.substr(l, r);
            cout << str << endl;
            break;
        case 3: {
            string insstr;
            int inspos;
            cin >> inspos;
            cin >> insstr;
            str.insert(inspos, insstr);
            cout << str << endl;
            break;
        }
        case 4: {
            string sub;
            cin >> sub;
            // match
            auto ret = str.find(sub);
            if (ret == str.npos)
                cout << -1;
            else
                cout << ret;
            cout << endl;
            break;
        }
        }
    }
    return 0;
}