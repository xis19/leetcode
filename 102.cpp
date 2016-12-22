#include <functional>
#include <queue>
#include <vector>
#include <utility>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


std::vector<std::vector<int>> levelOrder(TreeNode* root) {
    std::vector<std::vector<int>> result;
    if (!root) {
        return result;
    }

    std::queue<std::pair<TreeNode*, size_t>> q;

    q.push(std::make_pair(root, 0));
    while(!q.empty()) {
        auto front = q.front();
        q.pop();

        while(front.second >= result.size()) {
            result.emplace_back(std::vector<int>());
        }

        result[front.second].push_back(front.first->val);
        if (front.first->left) q.push(std::make_pair(front.first->left, front.second + 1));
        if (front.first->right) q.push(std::make_pair(front.first->right, front.second + 1));
    }

    return result;
}
