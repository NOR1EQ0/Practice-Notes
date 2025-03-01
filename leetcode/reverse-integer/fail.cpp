#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        string buf = to_string(x);
        bool sign = (x < 0);
        auto digitlen = buf.length() - sign;
        int num = 0, last = 0, iter_cnt = 0;
        if (digitlen > 10) {
            return 0;
        }
        auto pow10 = [sign](int base, int exp, bool& overflow) -> int {
            if (base >= 2 && exp >= 9) {
                overflow = true;
                return (sign? 1: -1);
            }
            for (int i = 0; i < exp; ++i) {
                base *= 10;
            }
            return base;
            };
        for (auto i = buf.begin() + sign; i != buf.end();++i) {
            bool of = false;
            num += (sign ? -1 : 1) * pow10(*i - '0', iter_cnt++, of);
            if (of) {return 0;}
            if (!sign) {
                if (num < last) {
                    return 0;
                }
            } else {
                if (num > last) {
                    return 0;
                }
            }
            last = num;
        }
        return num;
    }
};

int main() {
    Solution loc;
    int x = -2147483648;
    int res = loc.reverse(x);
    cout << res << endl;
    return 0;
}