#include <bits/stdc++.h>
using namespace std;using ll=long long;using ull=unsigned long long;constexpr ll MOD = 998244353;
static inline void solve(){
    char str[4];
    cin >> str;
    set<char> s;
    for(auto c:str){
        if (c) s.emplace(c);
    }
    if (s.size()==2) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}int main(){
#if defined(ONLINE_JUDGE)||1
ios::sync_with_stdio(0),cin.tie(0);
#elif 10
freopen("1.in","rb",stdin);
#endif
ll t=1;;while(t--){solve();}}