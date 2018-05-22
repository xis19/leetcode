struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


TreeNode* upsideDownBinaryTree(TreeNode* root) {
    //    1            1            1
    //   / \          / \          /
    //  2   3  ->    2   3   ->   2 - 3
    // / \          /            /
    // 4 5         4 - 5        4 - 5

    // Note: we always work on the left node, we ignore right node
    if (root == nullptr) return nullptr;

    // If it has no left child, it is the new root
    if (root->left == nullptr) return root;

    // Get the new root, which should be the left-most child.
    TreeNode* newRoot = upsideDownBinaryTree(root->left);

    // Now the left branch is done, the root->left should be the
    // new root for the old root
    root->left->right = root->right;
    root->left->left = root;

    // The old root should have no child.
    root->left = root->right = nullptr;

    return newRoot;
}
