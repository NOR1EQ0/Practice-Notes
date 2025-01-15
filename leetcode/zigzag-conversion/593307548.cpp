#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }
        vector<string> arr(numRows);
        int pos = 0;
        int len = s.length();
        bool reverse = false;
        for (int i = 0; pos < len; i += (reverse?-1:1)) {
            arr[i].push_back(s.at(pos++));
            if (i == 0) reverse = false;
            if (i == numRows - 1) reverse = true;

        }
        string ret;
        ret.reserve(len + 1);
        for (auto i : arr) {
            ret += i;
        }
        return ret;
    }
};

int main() {
    string s = "PAYPALISHIRING";
    int row = 4;
    Solution a;
    cout << a.convert(s, row) << endl;
    return 0;
}