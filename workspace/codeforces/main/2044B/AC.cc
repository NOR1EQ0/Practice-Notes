#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    string s;
    while (t--) {
        cin >> s;
        reverse(s.begin(), s.end());
        for(auto&c:s){
            if (c=='p')c='q';
            else if(c=='q')c='p';
        }
        cout<<s<<'\n';
    }
}