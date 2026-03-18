#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int failflag = 0;
        if (mat == target) return true;
        else failflag |= 0b0001;
        // 90
        int n = mat.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (failflag ^ 0b1111 == 0) {
                    return false;
                }
                int orig = mat[i][j];
            }
        }

        return failflag ^ 0b1111;
    }
};