#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (!n || n < 0) return false;
        int cnt = 0;
        for (int i = 0; i < sizeof(int)*CHAR_BIT - 1; ++i) {
            if (n % 2) cnt++;
            if (cnt >= 2) return false;
            n >>= 1;
        }
        return true;
    }
};

int main() {
    Solution a;
    vector<int> vec = {1, 16, 3, -2147483648, 0};
    for (const auto i: vec) {
        auto ret = a.isPowerOfTwo(i);
        cout << i << ": " << (ret ? "true": "false") << endl;
    }
}