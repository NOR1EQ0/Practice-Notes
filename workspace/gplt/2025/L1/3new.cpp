#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using u64 = uint64_t;
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define allit(x) auto i = (x).begin(); i != (x).end() 
#define bt "Bu Tie\n"
#define sn "Shi Nei\n"
#define br "Bu Re\n"
#define ss "Shu Shi\n"
#define endl '\n'

int main() {
    fastio
    // start
    int T, S, t;
    cin >> T >> S >> t;
    if (T>35&&S&&t>=33){
        cout << bt << T << endl;
    } else if (T>35&&t>=33&&(!S)){
        cout << sn << T << endl;
    } else if (S&&(T<=35||t<33)) {
        cout << br << t << endl;
    } else {
        cout << ss << t << endl;
    }
    return 0;
}