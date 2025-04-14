#include <bits/stdc++.h>
#define read cin>>b>>c;

using namespace std;
char opmarks[4] = "+-*";

inline int operate(int operation, int& b, int& c) {
    switch (operation) {
    case 0:
        return b + c;
        break;
    case 1:
        return b - c;
        break;
    case 2:
        return b * c;
        break;
    default:
        break;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    int opnum;
    cin >> n;
    while (n--) {
        string op;
        int a, b, c;
        cin >> op;
        auto ret = atoi(op.c_str());
        if (ret == 0) {
            if (op != "0") {
                opnum = op.front() - 'a';
                cin >> b >> c;
                auto res = operate(opnum, b, c);
                cout << b << opmarks[opnum] << c << '=' << res << '\n' << (to_string(b) + to_string(c) + to_string(res)).length() + 2 << '\n';
                continue;
            }
        }
        a = atoi(op.c_str());
        cin >> b;
        auto res = operate(opnum, a, b);
        cout << a << opmarks[opnum] << b << '=' << res << '\n' << (to_string(a) + to_string(b) + to_string(res)).length() + 2 << '\n';
    }

    return 0;
}