#include <algorithm>
#include <deque>
#include <vector>
#include <utility>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

std::vector<std::vector<int>> levelOrderBottom(TreeNode* root) {
    std::vector<std::vector<int>> result;
    if (!root) return result;

    std::deque<std::pair<TreeNode*, unsigned>> q;
    q.push_back(std::make_pair(root, 1));
    while(!q.empty()) {
        auto front = q.front();
        q.pop_front();

        if (front.second > result.size()) {
            result.push_back(std::vector<int>());
        }

        result.back().push_back(front.first->val);

        if (front.first->left) q.push_back(std::make_pair(front.first->left, front.second + 1));
        if (front.first->right) q.push_back(std::make_pair(front.first->right, front.second + 1));
    }

    std::reverse(result.begin(), result.end());
    return result;
}
