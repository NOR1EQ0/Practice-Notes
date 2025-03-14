#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        ret.emplace_back(vector<string>());
        // single char
        for (auto i : s) {
            ret.data()[0].emplace_back(i);
        }
        return ret;
    }
};

int main() {
    Solution loc;
    string a = "jhdvkfjd";
    cout << a.length() << endl;
    auto ret = loc.partition(a);
    {
        int cnt = 0;
        for (auto& i : ret) {
            int _cnt = 0;
            cout << "ret[" << (cnt++) << "]:" << endl;
            for (auto& j : i) {
                cout << "Elem[" << _cnt++ << "]:" << j << endl;
            }
        }
    }
    return 0;
}