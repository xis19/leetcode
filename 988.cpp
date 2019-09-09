#include <algorithm>
#include <functional>
#include <string>

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

std::string smallestFromLeaf(TreeNode* root) {
    std::string smallest;
    std::string current;

    std::function<void(TreeNode*)> traverse =
            [&traverse, &smallest, &current](TreeNode* node) {
        current.push_back(node->val);
        if (node->left == nullptr && node->right == nullptr) {
            std::string rev(current.rbegin(), current.rend());
            if (smallest.length() == 0) {
                smallest = rev;
            } else {
                smallest = std::min(smallest, rev);
            }
        } else {
            if (node->left != nullptr) {
                traverse(node->left);
            }
            if (node->right != nullptr) {
                traverse(node->right);
            }
        }
        current.pop_back();
    };
    traverse(root);

    std::transform(smallest.begin(), smallest.end(), smallest.begin(),
                   [](char ch) { return ch + 'a'; });

    return smallest;
}

