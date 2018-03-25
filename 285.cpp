#include <functional>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    if (p->right) {
        TreeNode* iterator = p->right;
        while(iterator->left) iterator = iterator->left;
        return iterator;
    }

    std::stack<TreeNode*> parents;
    std::function<void(TreeNode*)> findNode = [&findNode, &parents, p](TreeNode* node) -> void {
        if (node == p) {
            return;
        }
        parents.push(node);
        if (p->val > node->val) {
            findNode(node->right);
        } else {
            findNode(node->left);
        }
    };
    findNode(root);

    while(!parents.empty() && parents.top()->val < p->val) parents.pop();
    if (!parents.empty()) return parents.top();
    return nullptr;
}
