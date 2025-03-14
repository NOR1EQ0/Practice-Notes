#include <bits/stdc++.h>
#define lf '\n'

using namespace std;

using ull = uint64_t;

ull stk[1000000 * sizeof(ull)];
int top = -1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int t;
        cin >> t;
        string oper;
        oper.reserve(100);
        while (t--) {
            cin >> oper;
            ull pushnum;
            if (oper == "push") {
                cin >> pushnum;
                top++;
                *(stk + top) = pushnum;
            } else {
                if (oper == "pop") {
                    if (top == -1) {
                        cout << "Empty" << lf;
                    } else {
                        top--;
                    }
                } else if (oper == "query") {
                    if (top == -1) {
                        cout << "Anguei!" << lf;
                    } else {
                        cout << *(stk+top) << lf;
                    }
                } else if (oper == "size") {
                    cout << top+1 << lf;
                }
            }
        }
        top = -1;
    }
}