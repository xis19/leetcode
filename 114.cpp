#include <functional>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


void flatten(TreeNode* root) {
    if (root == nullptr) return;
    std::function<TreeNode*(TreeNode*)> traverse = [&traverse] (TreeNode* n) -> TreeNode* {
        TreeNode* tail = n;
        if (n->left != nullptr) {
            tail = traverse(n->left);
            tail->right = n->right;
            n->right = n->left;
            n->left = nullptr;
        }
        if (tail->right !=nullptr) {
            tail = traverse(n->right);
        }
        return tail;
    };
    traverse(root);
}
