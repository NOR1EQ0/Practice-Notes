#include <bits/stdc++.h>
using namespace std;using ll=long long;using ull=unsigned long long;constexpr ll MOD = 998244353;
static inline void solve() {
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    for(auto&i:a)cin>>i;for(auto&i:b)cin>>i;
    multimap<int,int> ma,mb;
    for(int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            if (b[i]==b[j]){
                mb.emplace(i,j);
            }
        }
    }
    ll ans=0;
    for(auto [x,y]:mb){
        if(a[x]!=a[y]){
            ans++;
        }
    }
}int main() {
#ifdef ONLINE_JUDGE
ios::sync_with_stdio(0),cin.tie(0);
#endif
0;
ll t=1;;while(t--){solve();}}