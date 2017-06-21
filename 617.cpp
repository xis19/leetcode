#include <functional>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    TreeNode* DummyTreeNode = new TreeNode(0);
    TreeNode* root = nullptr;

    std::function<TreeNode*(TreeNode*, TreeNode*)> visitor = [&visitor, &DummyTreeNode](TreeNode* t1, TreeNode* t2) -> TreeNode* {
        if (!t1) t1 = DummyTreeNode;
        if (!t2) t2 = DummyTreeNode;

        TreeNode* n = new TreeNode(t1->val + t2->val);
        if (t1->left || t2->left) n->left = visitor(t1->left, t2->left);
        if (t1->right || t2->right) n->right = visitor(t1->right, t2->right);

        return n;
    };

    if (t1 || t2)
        root = visitor(t1, t2);

    delete DummyTreeNode;

    return root;
}
