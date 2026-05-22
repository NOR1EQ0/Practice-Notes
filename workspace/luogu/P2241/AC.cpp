#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    using ll = long long;
    ll n, m;
    cin >> n >> m;
    ll sqr{},rec{};
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(i==j)sqr+=(n-i)*(m-j);
            else rec+=(n-i)*(m-j);
        }
    }
    cout<<sqr<<' '<<rec<<'\n';
}