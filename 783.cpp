#include <functional>
#include <limits>
#include <utility>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int minDiffInBST(TreeNode* root) {
    // Assume the result always exists
    int minDistance(std::numeric_limits<int>::max());

    std::function<std::pair<int, int>(TreeNode*)> traverse =
            [&traverse, &minDistance](TreeNode* node) -> std::pair<int, int> {
        const int value = node->val;

        int minVal = value;
        int maxVal = value;

        if (node->left != nullptr) {
            auto lhs = traverse(node->left);
            minDistance = std::min(minDistance, value - lhs.second);
            minVal = lhs.first;
        }

        if (node->right != nullptr) {
            auto rhs = traverse(node->right);
            minDistance = std::min(minDistance, rhs.first - value);
            maxVal = rhs.second;
        }

        return std::make_pair(minVal, maxVal);
    };

    traverse(root);
    return minDistance;
}
