#include <list>
#include <vector>
#include <utility>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


std::vector<int> inorderTraversal(TreeNode* root) {
    if (root == nullptr) return std::vector<int>();

    std::vector<int> result;
    // We use a flag to note if the node is visited or not
    std::list<std::pair<TreeNode*, bool>> nodes;
    nodes.push_back(std::make_pair(root, false));

    while(!nodes.empty()) {
        auto& front = nodes.front();
        if ((front.first->right == nullptr && front.first->left == nullptr) || front.second) {
            result.push_back(front.first->val);
            nodes.pop_front();
        } else {
            if (front.first->right) nodes.insert(std::next(std::begin(nodes)), std::make_pair(front.first->right, false));
            if (front.first->left) nodes.push_front(std::make_pair(front.first->left, false));
            front.second = true;
        }
    }

    return result;
}
