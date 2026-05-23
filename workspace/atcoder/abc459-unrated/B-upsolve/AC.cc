#include <bits/stdc++.h>
using namespace std;using ll=long long;using ull=unsigned long long;constexpr ll MOD = 998244353;
static inline void solve(){
    char str[20];
    cin>>str;
    switch (str[0])
    {
    case 'a':
    case 'b':
    case 'c':
        cout << '2';
        break;

    case 'd':
    case 'e':
    case 'f':
        cout << '3';
        break;

    case 'g':
    case 'h':
    case 'i':
        cout << '4';
        break;
    
    case 'j':
    case 'k':
    case 'l':
        cout << '5';
        break;

    case 'm':
    case 'n':
    case 'o':
        cout << '6';
        break;

    case 'p':
    case 'q':
    case 'r':
    case 's':
        cout << '7';
        break;

    case 't':
    case 'u':
    case 'v':
        cout << '8';
        break;

    case 'w':
    case 'x':
    case 'y':
    case 'z':
        cout << '9';
        break;
    
    default:
        break;
    }
}int main(){
#if defined(ONLINE_JUDGE)||1
ios::sync_with_stdio(0),cin.tie(0);
#elif 10
freopen("1.in","rb",stdin);
#endif
ll t=1;cin>>t;while(t--){solve();}}