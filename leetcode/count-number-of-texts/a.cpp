#include <bits/stdc++.h>
#define mod (int)((int)10e9 + 7)

using namespace std;

class Solution {
public:
    int countTexts(string pressedKeys) {
        uint64_t ans = 1;
        for (auto i = pressedKeys.begin(); i != pressedKeys.end(); ++i) {
            int len = 0;
            auto& current = *i;
            auto limit = 3;
            if (current == '7' || current == '9') limit++;
            for (auto j = i; len < limit; ++len, ++j) {
                if (*j != current)
                    break;
            }
            ans *= (pow(2, len));
        }
        return (int)(ans % mod);
    }
};

int main() {
    /**/
}