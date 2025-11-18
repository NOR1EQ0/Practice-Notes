#include <bits/stdc++.h>
#include "binary.hpp"

using namespace std;

int main() {
    cout << "sizeof(" << NAME_TO_STRING(TreeNode) "): " << sizeof(TreeNode) << endl;
    TreeNode root(17);
    TreeNode leaves[6] = { 2, 3, 4, 5, 6, 7 };
    assignLeavesOfTreeNode(root, leaves[0], leaves[1]);
    assignLeavesOfTreeNode(leaves[0], leaves[2], leaves[3]);
    assignLeavesOfTreeNode(leaves[1], leaves[4], leaves[5]);
    auto ret = treeTraversal(root, LevelOrder);
    print_stl_container_element_with_newline(ret);
    return 0;
}