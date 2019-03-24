#include <functional>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


bool flipEquiv(TreeNode* root1, TreeNode* root2) {
    std::function<bool(TreeNode*, TreeNode*)> traverse = [&traverse](TreeNode* n1, TreeNode* n2) {
        if (n1 == nullptr && n2 == nullptr) return true;
        if ((n1 == nullptr && n2 != nullptr) || (n1 != nullptr && n2 == nullptr)) return false;
        if (n1->val != n2->val) return false;

        return (traverse(n1->left, n2->left) && traverse(n1->right, n2->right)) || (traverse(n1->right, n2->left) && traverse(n1->left, n2->right));
    };

    return traverse(root1, root2);
}
