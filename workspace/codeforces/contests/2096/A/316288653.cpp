#include <bits/stdc++.h>

using namespace std;

char require[105];
int sticks[100];

int main() {
    /**
     * 5
     * <<><
     * 
     * 5>4>3<6>2
     * 4>3>2<5>1
     * 
     * 7
     * ><>>><
     * 
     * 6>5<7>4>3>2<8
     * 6<7>5<8<9<10>4
     * 3 4 2 5 6 7 1 
     */
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int maxn,minn;
    int t; cin >> t;while(t--){
        int n;cin>>n;
        minn=n-1;maxn=n-1;
        cin>>require;
        sticks[0]=n-1;
        char in;
        for (int i=1;i<n;++i){
            if (require[i-1] == '<') {
                minn--;sticks[i]=minn;
            } else {
                maxn++;sticks[i]=maxn;
            }
        }
        // int i = 0;
        // while((in=cin.get())!='\n'&&in!=EOF) {
        //     if (in=='<') {minn--;sticks[i++]=minn;} else {maxn++;sticks[i++]=maxn;}
        // }
        for(int i = 0; i < n-1; ++i) {cout<<sticks[i]-(minn-1)<<' ';}
        cout << sticks[n-1]-(minn-1) << '\n';
    }
    return 0;
}