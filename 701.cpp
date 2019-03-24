#include <functional>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


TreeNode* insertIntoBST(TreeNode* root, int val) {
    std::function<void(TreeNode*)> insert = [&insert, val](TreeNode* node) {
        const auto V = node->val;
        if (val > V) {
            if (node->right == nullptr) {
                node->right = new TreeNode(val);
            } else {
                insert(node->right);
            }
        } else {
            if (node->left == nullptr) {
                node->left = new TreeNode(val);
            } else {
                insert(node->left);
            }
        }
    };

    if (root == nullptr) {
        return new TreeNode(val);
    }

    insert(root);
    return root;
}
