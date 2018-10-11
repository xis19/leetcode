#include <functional>
#include <utility>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


TreeNode* increasingBST(TreeNode* root) {
    std::function<std::pair<TreeNode*, TreeNode*>(TreeNode*)> traverse = [&traverse](TreeNode* n) -> std::pair<TreeNode*, TreeNode*> {
        if (!n) {
            return std::make_pair(nullptr, nullptr);
        }

        TreeNode* root = n;
        TreeNode* tail = n;

        if (n->left) {
            std::tie(root, tail) = traverse(n->left);
            tail->right = n;
            tail = n;
        }

        n->left = nullptr;

        if (n->right) {
            std::tie(n->right, tail) = traverse(n->right);
        }

        return std::make_pair(root, tail);
    };

    return traverse(root).first;
}
