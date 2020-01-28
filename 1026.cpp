#include <functional>
#include <limits>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


int maxAncestorDiff(TreeNode* root) {
    std::vector<int> stack;
    int maxDiff = std::numeric_limits<int>::min();

    std::function<void(TreeNode*)> traverse =
            [&stack, &maxDiff, &traverse](TreeNode* node) {
        if (node == nullptr) return;

        int val = node->val;
        for (auto s: stack) {
            maxDiff = std::max(maxDiff, std::abs(val - s));
        }
        stack.push_back(val);
        traverse(node->left);
        traverse(node->right);
        stack.pop_back();
    };

    traverse(root);
    return maxDiff;
}
