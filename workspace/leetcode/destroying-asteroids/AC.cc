#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        ranges::sort(asteroids);
        long long cnt = mass;
        for (int i = 0; i < asteroids.size(); i++) {
            if (cnt >= asteroids[i]) {
                cnt += asteroids[i];
            } else {
                return false;
            }
        }
        return true;
    }
};