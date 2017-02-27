#include <queue>
#include <utility>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int findBottomLeftValue(TreeNode* root) {
    // Think about "row-wise" traverse of the tree
    std::queue<std::pair<TreeNode*, int>> nodes;
    int currentRow(-1), currentValue(0);
    nodes.push(std::make_pair(root, 0));
    while(!nodes.empty()) {
        auto item = nodes.front();
        nodes.pop();
        if (item.second > currentRow) {
            currentValue = item.first->val;
            currentRow = item.second;
        }
        if (item.first->left) {
            nodes.push(std::make_pair(item.first->left, item.second + 1));
        }
        if (item.first->right) {
            nodes.push(std::make_pair(item.first->right, item.second + 1));
        }
    }

    return currentValue;
}
