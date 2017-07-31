#include <functional>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool diameterOfBinaryTree(TreeNode* root) {
    if (!root) return 0;
    int maxDiameter = -1;
    std::function<int(TreeNode*)> visitor = [&visitor, &maxDiameter](TreeNode* n) -> int {
        int left(0), right(0);
        if (n->left) {
            left = visitor(n->left);
        }
        if (n->right) {
            right = visitor(n->right);
        }
        maxDiameter = std::max(maxDiameter, left + right + 1);
        return std::max(left + 1, right + 1);
    };
    visitor(root);
    // Note diameter is based on edge, not vertex
    return maxDiameter - 1;
}
