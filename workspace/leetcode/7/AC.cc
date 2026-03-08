#include <bits/stdc++.h>

using namespace std;

string MAX = to_string(INT_MAX);
string MIN = to_string(INT_MIN);

class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        auto nega = s.front() == '-';
        std::reverse(s.begin() + nega, s.end());
        if (nega && s.size() == MIN.size() && s > MIN) return 0;
        else if (s.size() == MAX.size() &&  s > MAX)
            return 0;
        return stoi(s);
    }
};

int main() {
    vector<int> v = {
        123, -123, 120, 0,
        -563847412 // -214748365
    };
    for (auto i : v) {
        cout << i << ' ' << Solution().reverse(i) << endl;
    }
}