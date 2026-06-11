// I just think it was binary tree at first but clearly this solution was rejected
#include <bits/stdc++.h>
using namespace std;

class Solution {
    using ll = long long;
    static constexpr auto MOD = (long long)(1e9 + 7);
    struct node {
        ptrdiff_t l = 0;
        ptrdiff_t r = 0;
    };
    static ll dfs(vector<node>& tree, ll dep, ll idx, ll mx) {
        if (tree[idx].l == 0 && tree[idx].r == 0) {
            mx = max(dep, mx);
            return mx;
        }
        return max(dfs(tree, dep + 1, tree[idx].l, mx),
                   dfs(tree, dep + 1, tree[idx].r, mx));
    }

public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        vector<node> tree;
        for (auto& edge : edges) {
            ll mx_n = max(edge[0], edge[1]) + 1;
            if (mx_n > tree.size()) {
                tree.resize(mx_n);
            }
            (tree[edge[0]].l ? tree[edge[0]].r : tree[edge[0]].l) = edge[1];
            // *(decltype(node::l)*)((char*)&tree[edge[0]] + sizeof(node::l) * (tree[edge[0]].l != 0)) = edge[1];
        }
        vector<int> stk;
        ll mx = 0;
        mx = dfs(tree, 0, 1, mx);
        ll ans = (1 << (mx - 1)) % MOD;
        return ans;
    }
};

int main() {
    vector<vector<vector<int>>> input = {
        {{1, 2}},                         // 1
        {{1, 2}, {1, 3}, {3, 4}, {3, 5}}, // 2
        {{2, 4}, {1, 5}, {1, 2}, {1, 3}}  // 2
    };
    for (int i = 0; i < input.size(); i++) {
        cout << i << ' ' << Solution().assignEdgeWeights(input[i]) << endl;
    }
}