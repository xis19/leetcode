#include <queue>
#include <utility>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


std::vector<int> largestvalues(TreeNode* root) {
    if (!root) return std::vector<int>();

    std::queue<std::pair<TreeNode*, int>> nodes;
    std::vector<int> result;
    nodes.push(std::make_pair(root, 0));
    int thisMax(0), depth(-1);
    while(!nodes.empty()) {
        auto item = nodes.front();
        nodes.pop();

        if (item.second > depth) {
            if (depth != -1) result.push_back(thisMax);
            thisMax = item.first->val;
            depth = item.second;
        }

        if (thisMax <= item.first->val) thisMax = item.first->val;

        if (item.first->left) nodes.push(std::make_pair(item.first->left, depth + 1));
        if (item.first->right) nodes.push(std::make_pair(item.first->right, depth + 1));
    }
    result.push_back(thisMax);
    return result;
}
