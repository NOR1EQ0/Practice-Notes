#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int m,d;
    cin>>m>>d;
    #define FESTIVAL(x,y) ((m==x)&&(d==y))
    if (FESTIVAL(1,7) or FESTIVAL(3,3) or FESTIVAL(5,5) or FESTIVAL(7,7) or FESTIVAL(9,9)) {
        cout << "Yes\n"sv;
    } else {
        cout << "No\n"sv;
    }
}