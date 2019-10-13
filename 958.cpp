#include <list>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isCompleteTreeRowTraverse(TreeNode* root) {
    if (root == nullptr) return true;

    std::list<TreeNode*> queue;
    queue.push_back(root);

    bool meetNull = false;
    while(!queue.empty()) {
        auto front = queue.front();
        queue.pop_front();

        if (front == nullptr) {
            meetNull = true;
            continue;
        }

        if (meetNull && front) {
            return false;
        }

        queue.push_back(front->left);
        queue.push_back(front->right);
    }

    return true;
}
