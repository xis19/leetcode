#include <functional>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int longestConsecutive(TreeNode* root) {
    int longest(0);
    std::function<void(TreeNode*, int)> visitor = [&visitor, &longest](TreeNode* node, int l) {
        longest = std::max(l, longest);
        if (node->left)
            visitor(node->left, node->left->val - node->val == 1 ? l + 1 : 1);
        if (node->right)
            visitor(node->right, node->right->val - node->val == 1 ? l + 1 : 1);
    };

    if (root != nullptr)
        visitor(root, 1);

    return longest;
}
