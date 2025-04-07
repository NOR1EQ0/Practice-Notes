#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 0;
        bool start = false;
        int sum = 0;
        bool producted = false;
        for (int i = 7; i >= 0; --i) {
            int mod = n / pow10(i);
            if (mod && !start) {
                start = true;
            }
            if (start) {
                int single = mod - (n / pow10(i + 1) * 10);
                if (!product && !producted) {
                    product = single;
                    producted = true;
                } else {
                    product *= single;
                }
                sum += single;
            }
        }
        return product - sum;
    }

    int pow10(int upper) {
        int ret = 1;
        for (int i = 0; i < upper; ++i) {
            ret *= 10;
        }
        return ret;
    }
};

int main() {
    Solution sol;
    vector<pair<int, int>> inputVec = {
        {234, 15}, {4421, 21}, {705, -12}
    };
    for (auto i : inputVec) {
        cout << "Input: " << i.first << " | Expected: " << i.second << " | Calculated: " << sol.subtractProductAndSum(i.first) << '\n';
    }
    return 0;
}