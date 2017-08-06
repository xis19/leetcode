#include <functional>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


bool findTarget(TreeNode* root, int k) {
    std::function<bool(TreeNode*, int)> find = [&find](TreeNode* n, int val) -> bool {
        if (n->val == val) return true;
        if (n->val > val && n->left) {
            return find(n->left, val);
        }
        if (n->val < val && n->right) {
            return find(n->right, val);
        }
        return false;
    };

    std::function<bool(TreeNode*)> exists = [&exists, &find, root, k](TreeNode* n) -> bool {
        if (!n) return false;
        int residue = k - n->val;
        return (residue != n->val ? find(root, residue) : false) || exists(n->left) || exists(n->right);
    };

    return exists(root);
}
