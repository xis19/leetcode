#include <functional>
#include <unordered_set>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* sufficientSubset(TreeNode* root, int limit) {
    // It is possible that we erase the whole tree, in this case we will set a
    // fake header.
    if (root == nullptr) return nullptr;

    TreeNode* fakeRoot = new TreeNode(0);
    fakeRoot->left = root;
    fakeRoot->right = nullptr;

    std::unordered_set<TreeNode*> nodeToBeRemoved;

    std::function<bool(TreeNode*, int)> traverse = [&traverse, &nodeToBeRemoved, limit](TreeNode* n, int k) -> bool {
        int s = k + n->val;
        if (n->left == nullptr && n->right == nullptr) {
            if (s < limit) {
                nodeToBeRemoved.insert(n);
                return true;
            }
            return false;
        }

        bool removeLeft = n->left == nullptr ? true : traverse(n->left, s);
        bool removeRight = n->right == nullptr ? true : traverse(n->right, s);
        bool shouldRemoveThis = removeLeft & removeRight;
        if (shouldRemoveThis) {
            nodeToBeRemoved.insert(n);
        }
        return shouldRemoveThis;
    };

    std::function<TreeNode*(TreeNode*)> erase = [&erase, &nodeToBeRemoved](TreeNode* n) -> TreeNode* {
        if (n->left != nullptr) n->left = erase(n->left);
        if (n->right != nullptr) n->right = erase(n->right);

        if (nodeToBeRemoved.find(n) != nodeToBeRemoved.end()) {
            // erase it -- LeetCode bug, do not delete node!
            // delete n;
            return nullptr;
        }
        return n;
    };

    traverse(fakeRoot, 0);
    auto result = erase(fakeRoot->left);
    delete fakeRoot;
    return result;
}

