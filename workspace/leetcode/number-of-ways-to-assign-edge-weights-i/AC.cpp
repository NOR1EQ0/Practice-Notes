#include <bits/stdc++.h>
using namespace std;

class Solution {
    using ll = long long;
    using node = vector<int>;
    static constexpr auto MOD = (long long)(1e9 + 7);
    static ll dfs(vector<node>& tree, ll x, ll f) {
        ll maxdep = 0;
        for (auto& y : tree[x]) {
            if (y == f) {
                continue;
            }
            maxdep = max(maxdep, dfs(tree, y, x) + 1);
        }
        return maxdep;
    }

public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        vector<node> tree(edges.size() + 2);
        for (auto& edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
            // *(decltype(node::l)*)((char*)&tree[edge[0]] + sizeof(node::l) * (tree[edge[0]].l != 0)) = edge[1];
        }
        ll mx = dfs(tree, 1, 0);
        mx--;
        ll ans = 1;
        for (ll i = 0; i < mx; i++) {
            ans <<= 1;
            ans %= MOD;
        }
        return ans;

        // for (int i = 1; i < tree.size(); i++) {
        //     mx = max(mx, dfs(tree, 0, i));
        // }
        // ll ans = (1ull << (mx - 1)) % MOD;
        // mx--;
        // ll ans = 1;
        // for (ll i = 0; i < mx; i++) {
        //     ans <<= 1;
        //     ans %= MOD;
        // }
    }
};

int main() {
    vector<vector<vector<int>>> input = {
        {{1, 2}},                         // 1
        {{1, 2}, {1, 3}, {3, 4}, {3, 5}}, // 2
        {{2, 4}, {1, 5}, {1, 2}, {1, 3}}, // 2
        {{3, 2}, {2, 1}},                 // 2
        {{3, 4}, {2, 5}, {1, 2}, {2, 3}}  // 4
    };
    for (int i = 0; i < input.size(); i++) {
        cout << i << ' ' << Solution().assignEdgeWeights(input[i]) << endl;
    }
}