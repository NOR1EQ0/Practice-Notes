#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int height = grid.size();
        int width = grid.front().size();
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                bool lexist = j != 0,
                     uexist = i != 0;
                int l = lexist ? grid[i][j - 1] : 0;
                int u = uexist ? grid[i - 1][j] : 0;
                int diff = lexist && uexist ? grid[i - 1][j - 1] : 0;
                grid[i][j] = grid[i][j] + l + u - diff;
            }
        }
        int ans = 0;
        for (auto& _ : grid) {
            for (auto i : _) {
                if (i <= k) ans++;
            }
        }
        return ans;
    }
};

int main() {
    using PINPUT = pair<vector<vector<int>>, int>;
    vector<PINPUT> input(2);
    input[0] = make_pair<vector<vector<int>>, int>({{7, 6, 3}, {6, 6, 1}}, 18);
    input[1] = make_pair<vector<vector<int>>, int>({{7, 2, 9}, {1, 5, 0}, {2, 6, 6}}, 20);
    for (auto& P: input) {
        cout << Solution().countSubmatrices(P.first, P.second) << endl;
    }
}