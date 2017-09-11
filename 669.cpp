#include <functional>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


TreeNode* trimBST(TreeNode* root, int L, int R) {
    // This actually causes memory leakage since it does not delete unused nodes
    std::function<TreeNode*(TreeNode*)> traverse = [L, R, &traverse](TreeNode* node) -> TreeNode* {
        if (node == nullptr) {
            return nullptr;
        }

        int value = node->val;
        if (value < L) {
            return traverse(node->right);
        }
        if (value > R) {
            return traverse(node->left);
        }
        node->left = traverse(node->left);
        node->right = traverse(node->right);

        return node;
    };

    return traverse(root);
}
