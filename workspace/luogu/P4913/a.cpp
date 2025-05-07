#include <bits/stdc++.h>

using namespace std;

typedef struct node {
    int left;
    int right;
}*pnode;

static int max_depth = 0;
pnode nodes;

int traversal(node& node, int depth = 0) {
    if (node.left)
    traversal(nodes[node.left], depth);
    if (node.right)
    traversal(nodes[node.right], depth);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    nodes = new node[n];
    for (int i = 0; i < n; ++i) {
        cin >> nodes[i].left >> nodes[i].right;
    }
    return 0;
}