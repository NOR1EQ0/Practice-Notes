#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int ansm = m-k+1, ansn = n-k+1;
        vector<vector<int>> ans(ansm, vector<int>(ansn));
        for (int i = 0; i < ansm; i++) {
            for (int j = 0; j < ansn; j++) {
                int num = INT_MAX;
            }
        }
    }
};

int main() {
}