#include <bits/stdc++.h>

using namespace std;

typedef struct node {
    int left;
    int right;
}*pnode;

static int max_depth = 0;
pnode nodes;

int traversal(node& node, int depth = 0) {
    int left = 0, right = 0;
    if (node.left)
        left = traversal(nodes[node.left - 1], depth);
    if (node.right)
        right = traversal(nodes[node.right - 1], depth);
    int retDepth = max(left, right);
    return retDepth + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin >> n;
    nodes = new node[n];
    for (int i = 0; i < n; ++i) {
        cin >> nodes[i].left >> nodes[i].right;
    }
    auto ret = traversal(nodes[0]);
    cout << ret << '\n';
    return 0;
}