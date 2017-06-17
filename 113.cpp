#include <functional>
#include <numeric>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

std::vector<std::vector<int>> pathSum(TreeNode* root, int sum) {
    std::vector<std::vector<int>> result;
    if (!root) return result;

    std::vector<int> history;
    std::function<void(TreeNode*)> visitor = [&visitor, &history, &result, sum](TreeNode* n) -> void {
        history.push_back(n->val);

        if (!n->left && !n->right) {
            if (std::accumulate(history.begin(), history.end(), 0) == sum) {
                result.push_back(history);
            }
        } else {
            if (n->left) visitor(n->left);
            if (n->right) visitor(n->right);
        }

        history.pop_back();
    };

    visitor(root);
    return result;
}
