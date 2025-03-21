#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        bool flag = false;
        for (auto i = s.rbegin(); i != s.rend(); ++i) {
            if (*i != ' ') {
                flag = true;
                ans++;
            }
            if (*i == ' ' && flag) {
                break;
            }
        }
        return ans;
    }
};

int main() {
    string s = "Today is a nice day";
    Solution a;
    cout << a.lengthOfLastWord(s) << endl;
    return 0;
}