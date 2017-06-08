#include <functional>
#include <string>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


std::string tree2str(TreeNode* t) {
    std::function<std::string(TreeNode*)> visitor = [&](TreeNode* n) -> std::string {
        std::string s = std::to_string(n->val);
        if (n->left) {
            s += '(' + visitor(n->left) + ')';
        } else if (n->right) {
            s += "()";
        }
        if (n->right) {
            s += '(' + visitor(n->right) + ')';
        }
        return s;
    };

    if (t)
        return visitor(t);
    else
        return std::string();
}
