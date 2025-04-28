#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using u64 = uint64_t;
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
#define allit(x)          \
    auto i = (x).begin(); \
    i != (x).end()
#define allparam(x) (x).begin(), (x).end()
#define endl '\n'

#define read(container,n) for(int i=0;i<l;++i){container.value_type tmp;cin>>tmp;container.push_back(tmp);};
#define epread(containertype,container,n) for(int i=0;i<n;++i){containertype::value_type tmp;cin>>tmp;container.emplace_back(tmp);};
#define loop(i,l) for(int i=0;i<l;++i)
int main()
{
    fastio;
    // start
    int n, m;
    cin >> n >> m;
    vector<int> vec;
    vec.reserve(n);
    epread(vector<int>,vec,n);
    while (m--)
    {
        int optype;
        cin >> optype;
        if (optype == 1)
        {
            int l1,l2;
            cin >> l1;
            vector<int> seq(l1);
            vector<int> pattern;
            for (int i = 0; i < l1; ++i)
            {
                cin >> seq[i];
            }
            cin >> l2;
            pattern.reserve(l2+1);
            loop(i,l2) {
                int tmp; cin >> tmp; pattern.emplace_back(tmp);
            }
            auto it = search(allparam(vec), allparam(seq));
            auto index = it - vec.begin();
            if (it != vec.end())
            {
                vec.erase(it, it + l1);
                vec.insert(vec.begin() + index, pattern.begin(), pattern.end());
            }
        }
        else if (optype == 2)
        {
            vector<int> another = vec;
            loop(i,n-1)
            {
                if ((vec[i]+vec[i+1])%2==0) {vec.insert(vec.begin()+i, (vec[i]+vec[i+1])/2);i++;}
            }
        }
        else
        {
            int l,r;cin>>l>>r;
            l--,r--;
            vector<int> orig;
            for_each(vec.begin()+l, vec.begin()+r+1, [&orig](int& val) {orig.emplace_back(val);});
            for(int i = r, index=0; i >= l; --i, ++index) {
                vec[i]=orig[index];
            }
        }
    }
    for(allit(vec)-1; ++i) {
        cout << *i << ' ';
    } cout << vec.back() << '\n';
    return 0;
}