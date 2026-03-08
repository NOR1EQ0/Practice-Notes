#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        std::reverse(s.begin() + (s.front() == '-'), s.end());
        try {
            return stoi(s);
        } catch (...) {
            return 0;
        }
    }
};

int main() {
    vector<int> v = {
        123, -123, 120, 0};
    for (auto i : v) {
        cout << i << ' ' << Solution().reverse(i) << endl;
    }
}