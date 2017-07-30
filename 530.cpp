#include <cstdlib>
#include <functional>
#include <limits>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int getMinimumDifference(TreeNode* root) {
    static const int MAX_INT = std::numeric_limits<int>::max();
    typedef struct {
        int min, max, minDiff;
    } _Result;
    std::function<_Result(TreeNode*)> visitor = [&visitor](TreeNode* node) -> _Result {
        _Result result{node->val, node->val, MAX_INT};
        if (node->left) {
            _Result leftNodeResult = visitor(node->left);
            result.min = std::min(leftNodeResult.min, result.min);
            result.max = std::max(leftNodeResult.max, result.max);
            result.minDiff = std::min(result.minDiff, std::abs(node->val - leftNodeResult.max));
            result.minDiff = std::min(result.minDiff, leftNodeResult.minDiff);
        }
        if (node->right) {
            _Result rightNodeResult = visitor(node->right);
            result.min = std::min(rightNodeResult.min, result.min);
            result.max = std::max(rightNodeResult.max, result.max);
            result.minDiff = std::min(result.minDiff, std::abs(node->val - rightNodeResult.min));
            result.minDiff = std::min(result.minDiff, rightNodeResult.minDiff);
        }

        return result;
    };

    return visitor(root).minDiff;
}
