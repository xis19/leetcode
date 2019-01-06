#include <functional>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


bool isUnivalTree(TreeNode* root) {
    if (!root) return true;
    const int VALUE = root->val;

    std::function<bool(TreeNode*)> trav = [&](TreeNode* n) -> bool {
        if (!n) return true;
        if (n->val != VALUE) {
            return false;
        }
        return trav(n->left) && trav(n->right);
    };

    return trav(root);
}
