#include <functional>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


TreeNode* pruneTree(TreeNode* root) {
    std::function<bool(TreeNode*)> prune = [&prune](TreeNode* node) -> bool {
        // return true if both nodes are 0
        if (node == nullptr) return true;

        auto left = prune(node->left);
        auto right = prune(node->right);
        if (left) node->left = nullptr;
        if (right) node->right = nullptr;
        if (left && right && node->val == 0) return true;

        return false;
    };

    if (!root) return nullptr;
    if (prune(root)) return nullptr;
    return root;
}
