#include <functional>
#include <unordered_set>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class FindElements {
    std::unordered_set<int> values;
public:
    FindElements(TreeNode* root) {
        std::function<void(TreeNode*, int)> traverse = [this, &traverse](TreeNode* n, int v) {
            values.insert(v);
            if (n->left) {
                traverse(n->left, v * 2 + 1);
            }
            if (n->right) {
                traverse(n->right, v * 2 + 2);
            }
        };
        traverse(root, 0);
    }

    bool find(int target) {
        return values.find(target) != values.end();
    }
};
