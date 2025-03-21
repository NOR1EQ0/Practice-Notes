#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        auto pos = haystack.find(needle);
        return pos == string::npos ? -1 : pos;
    }
};

int main() {
    string str1 = "leetcode";
    string str2 = "leeto";
    Solution a;
    cout << a.strStr(str1, str2) << endl;
    return 0;
}