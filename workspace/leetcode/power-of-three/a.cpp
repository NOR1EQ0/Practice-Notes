#include <bits/stdc++.h>

using namespace std;

const int a[] = {3, 9, 27, 81};

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n == 1) return true;
        if (!n || n < 0) return false;
        if (!(n%5)) return false;

        for (int i = 3; i >= 0; --i) {
            if (n % a[i] == 0) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution a;
    vector<int> vec = {
        // 1, 16, 3, -2147483648, 0
        27, 0, 9, 45, 6, -2147483648, 
    };
    for (const auto i : vec) {
        auto ret = a.isPowerOfThree(i);
        cout << i << ": " << (ret ? "true" : "false") << endl;
    }
}