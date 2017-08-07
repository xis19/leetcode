#include <functional>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isSubtree(TreeNode* s, TreeNode* t) {
    std::function<bool(TreeNode*, TreeNode*)> isSameTree = [&isSameTree](TreeNode* n1, TreeNode* n2) -> bool {
        if (n1 == nullptr && n2 == nullptr) return true;
        if (bool(n1) ^ bool(n2)) return false;
        if (n1->val != n2->val) return false;
        return isSameTree(n1->left, n2->left) && isSameTree(n1->right, n2->right);
    };

    std::function<bool(TreeNode*)> traverse = [&traverse, &isSameTree, t](TreeNode* r) -> bool {
        if (!r) return false;
        return isSameTree(r, t) || traverse(r->left) || traverse(r->right);
    };

    return traverse(s);
}
