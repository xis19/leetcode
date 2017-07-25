#include <list>
#include <vector>
#include <utility>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

std::vector<int> rightSideView(TreeNode* root) {
    std::vector<int> result;
    if (!root) return result;

    std::list<std::pair<TreeNode*, int>> queue;
    queue.push_back(std::make_pair(root, 0));
    while(!queue.empty()) {
        auto front = queue.front();
        queue.pop_front();
        if (front.second > static_cast<int>(result.size()) - 1) {
            result.push_back(front.first->val);
        } else {
            result.back() = front.first->val;
        }
        if (front.first->left) queue.push_back(std::make_pair(front.first->left, front.second + 1));
        if (front.first->right) queue.push_back(std::make_pair(front.first->right, front.second + 1));
    }

    return result;
}
