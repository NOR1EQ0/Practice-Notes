#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using u64 = uint64_t;
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define allit(x) auto i = (x).begin(); i != (x).end() 
#define allparam(x) (x).begin(), (x).end() 
#define endl '\n'
#define loop(i,l) for(int i=0;i<l;++i)
#define read(containertype,container,n) for(int i=0;i<l;++i){containertype::value_type tmp;cin>>tmp;container.push_back(tmp);};
#define epread(containertype,container,n) for(int i=0;i<n;++i){containertype::value_type tmp;cin>>tmp;container.emplace_back(tmp);};

int main() {
    /**
     * (((2+3)*4)-(5/(6*7)))
     * Meet left braces 3 times, `braces`=3, status=left
     * Meet 2+3, pushback 2+3
     * Meet right brace 1 time, `braces`=2, stutus=right, print 2+3, pop 2+3
     * Meet *4, pushback *4
     * Meet right brace 1 time, `braces`=1, status=right, print *4, pop *4
     * Meet -, pushback -
     * Meet left brace 1 time, `braces`=2, status=left
     * Meet 5/, pushback 5/
     * Meet left brace 1 time, `braces`=3, status=left
     * Meet 6*7, pushback 6*7
     * Meet right brace 1 time, `braces`=2, status=right, print 6*7, pop 6*7
     * Meet right brace 1 time, `braces`=1, status=right, print 5/, pop 5/
     * Meet right brace 1 time, `braces`=0, status=right, print -, pop -
     * Over
     */
    fastio;
    // start
    int braces = 0;
    string s;
    s.reserve(200);
    cin >> s;
    stack<string> strstack;
    bool left = true;
    for(allit(s); ++i) {
        if (*i == '(') {
            left=true;
            braces++;continue;
        }
        if (braces==0) break;
        if (*i == ')') {
            braces--;left=false;
            // if (!strstack.empty()) {
            cout << strstack.top() << '\n';strstack.pop();
            // }
            continue;
        }
        auto rbraceit = find(i, s.end(), left?'(':')');
        if (rbraceit!=s.end()) {
            string part;
            for (auto start = i; start != rbraceit; start++) {
                part.push_back(*start);
            }
            strstack.push(part);
            i=rbraceit-1;
        }

    }
    return 0;
}